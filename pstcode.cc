#include <string>
#include <list>
#include <vector>
#include <utility>
#include <cstdio>
#include "symbtable.h"
#include "pstcode.h"

using namespace std;

// Stack address which holds the count of globals
// in the I_PROG call
int global_count_loc = 0;

void PstackCode::add(int op)
{
	code.push_back(op);
}

void PstackCode::add_dup()
{
	// -- w
	add(I_CONSTANT);
	add(ADDR_TEMP);
	// -- addr_temp w
	add(I_SWAP);
	// -- w addr_temp
	add(I_ASSIGN);
	add(1);
	add(I_CONSTANT);
	add(ADDR_TEMP);
	add(I_VALUE);
	// -- w
	add(I_CONSTANT);
	add(ADDR_TEMP);
	add(I_VALUE);
	// -- w w
}

void PstackCode::begin_prog()
{
	// execution starts at address 1
	add(0);
	add(I_PROG);
  // Backfill this later
  global_count_loc = pos();
	add(0);
	add(pos() + 1);
	add(I_JMP);
	add(0);  // position 5, will be patched up at the end of prolog()
}

void PstackCode::prolog(SymbolTable &fvsyms)
{
  // Add typechecking to builtins builtins
  std::vector<type_t> type_list;
  type_list.push_back(TY_STR);
	fvsyms.insert(Symbol("puts", type_list, pos()));
	add(I_VARIABLE);
	add(0);
	add(-1);
	add(I_VALUE);
	const int looploc = pos();
	add_dup();            // ( str+k str+k --- )
	add(I_VALUE);         // ( str+k chr --- )
	add_dup();            // ( str+k chr chr --- )
	add(I_JR_IF_FALSE);
	add(0);               // ( str+k chr --- )
	const int patchloc = pos() - 1;
	add(C_WRITE);
	add(1);               // ( str+k --- )
	add(I_CONSTANT);
	add(1);               // ( str+k 1 --- )
	add(I_ADD);           // ( str+k+1 --- )
	add(I_JR);
	add(looploc - (pos() - 1));
	at(patchloc) = pos() - (patchloc - 1);
	add(I_ENDPPROC);
	add(1);

  type_list.clear();
  type_list.push_back(TY_INT);
	fvsyms.insert(Symbol("putn", type_list, pos()));
	add(I_VARIABLE);
	add(0);
	add(-1);
	add(I_VALUE);
	add(I_WRITE);
	add(1);
	add(I_ENDPPROC);
	add(1);

  type_list.clear();
  type_list.push_back(TY_DOUBLE);
	fvsyms.insert(Symbol("putd", type_list, pos()));
	add(R_VARIABLE);
	add(0);
	add(-1);
	add(R_VALUE);
	add(R_WRITE);
	add(1);
	add(I_ENDPPROC);
	add(1);

  // getnum() function added (11/28) 
  type_list.clear();
  fvsyms.insert(Symbol("getnum", type_list, pos()));
  add(I_VARIABLE);
  add(0);
  add(-1);
  add(I_READ);
  add(1);
  add(I_ENDPPROC);
  add(0);

  type_list.clear();
  type_list.push_back(TY_DOUBLE);
	fvsyms.insert(Symbol("dtoi", type_list, pos(), TY_INT));
  // Push retval address
	add(I_VARIABLE);
	add(0);
	add(-2);
  // Push argument address
	add(R_VARIABLE);
	add(0);
	add(-1);
  // Dereference argument
	add(R_VALUE);
  // Pop and push as double
	add(R_TO_I);
  // Assign value to return address
  add(I_ASSIGN);
  add(1);
  // End
  add(I_ENDPPROC);
  add(1);

  type_list.clear();
  type_list.push_back(TY_INT);
	fvsyms.insert(Symbol("itod", type_list, pos(), TY_DOUBLE));
  // See above
	add(R_VARIABLE);
	add(0);
	add(-2);
	add(I_VARIABLE);
	add(0);
	add(-1);
	add(I_VALUE);
	add(I_TO_R);
  add(R_ASSIGN);
  add(1);
  add(I_ENDPPROC);
  add(1);

  type_list.clear();
	fvsyms.insert(Symbol("exit", type_list, pos()));
	add(I_ENDPROG);

	// Patch up the JMP to the beginning of the program proper
	at(5) = pos();
}


void PstackCode::end_prog()
{
	list<pair<string, int> >::iterator i;
	string::iterator j;

	// Write strings after the end of the program.
	for(i=strings.begin(); i!=strings.end(); ++i) {
		at(i->second) = pos();
		for(j=i->first.begin(); j!=i->first.end(); ++j)
			add(*j);
		add(0);
	}
}

vector<int> PstackCode::codevec() const
{
	return code;
}

bool PstackCode::write(FILE *file, bool binary) const
{
	if(!file)
		return false;
	
	vector<int>::const_iterator i;
	for(i=code.begin(); i!=code.end(); ++i) {
		int iv = *i;
		if(binary) {
			fwrite(&iv, sizeof(int), 1, file);
		} else {
			fprintf(file, "%d\n", iv);
		}
	}

	return !ferror(file);
}
	
int PstackCode::pos() const
{
	return code.size();
}

int PstackCode::at(int p) const
{
	return code[p];
}

int &PstackCode::at(int p)
{
	return code[p];
}

void PstackCode::add_string(const string &value, int pos)
{
	strings.push_back(pair<string,int>(value,pos));
}
