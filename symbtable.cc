#include <string>
#include <list>
#include "symbtable.h"

using namespace std;

ArgumentChecker::ArgumentChecker(std::string function_name, std::vector<type_t> arg_types_list){
  fun_name  = function_name;
  arg_types = arg_types_list;
  num_args  = arg_types.size();
}

ArgumentChecker::ArgumentChecker(){
}

bool ArgumentChecker::check_args(std::vector<type_t> given_arg_types){
  if(given_arg_types.size() != arg_types.size())
    throw WrongNumberArguments(fun_name, arg_types.size(), given_arg_types.size());
  // TODO type checking
}

Symbol::Symbol()
	: nam(), typ(TY_BAD)
{}

Symbol::Symbol(const string &name, type_t type, int address)
	: nam(name), typ(type), addr(address)
{}

Symbol::Symbol(const string &name, std::vector<type_t> given_arg_types, int address)
	: nam(name), addr(address), typ(TY_FUNC)
{
  checker = ArgumentChecker(name, given_arg_types);
}

bool Symbol::check_args(std::vector<type_t> arg_types_list){
  checker.check_args(arg_types_list);
}

const string &Symbol::name() const
{
	return nam;
}

type_t &Symbol::type()
{
	return typ;
}

type_t Symbol::type() const
{
	return typ;
}

int &Symbol::address()
{
	return addr;
}

int Symbol::address() const
{
	return addr;
}

bool Symbol::operator<(const Symbol &s) const
{
	return nam < s.nam;
}

bool Symbol::operator==(const Symbol &s) const
{
	return nam == s.nam;
}

bool Symbol::operator!=(const Symbol &s) const
{
	return nam != s.nam;
}

SymbolTable::SymbolTable()
	: hashes(1) // one (empty) hash table
{}

SymbolTable::SymbolTable(const SymbolTable &st)
	: hashes(st.hashes)
{}

SymbolTable &SymbolTable::operator=(const SymbolTable &st)
{
	if(this != &st)
		hashes = st.hashes;

	return *this;
}

Symbol *SymbolTable::operator[](const string &s) 
{
	for(symtabint::iterator i=hashes.begin(); i != hashes.end(); ++i) {
		symtabsingle::iterator pos = i->find(s);
		if (pos != i->end())
			return &(pos->second);
	}
	
	return 0;
}

const Symbol *SymbolTable::operator[](const string &s) const
{
	for(symtabint::const_iterator i=hashes.begin(); i != hashes.end(); ++i) {
		symtabsingle::const_iterator pos = i->find(s);
		if (pos != i->end())
			return &(pos->second);
	}
	
	return 0;
}

bool SymbolTable::insert(Symbol s) 
{
	hashes.front().insert(make_pair(s.name(), s));
	return true;
}

void SymbolTable::enter() 
{
	hashes.push_front(symtabsingle());
}

void SymbolTable::leave() 
{
	// We should not pop off the first element
	if(hashes.size() > 1)
		hashes.pop_front();
}

bool SymbolTable::exists(const string &str) const 
{
	for(symtabint::const_iterator i=hashes.begin(); i!=hashes.end(); ++i)
		if(i->count(str))
			return true;

	return false;
}

int SymbolTable::numvars() const
{
	return hashes.front().size();
}

int SymbolTable::levelof(const string &str) const 
{
	symtabint::const_iterator i;
	int j = 0;
	for(i=hashes.begin(); i != hashes.end(); ++i, ++j)
		if(i->count(str))
			return j;

	return -1;
}

