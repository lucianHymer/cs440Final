#ifndef SYMBTABLE_H_INCLUDED
#define SYMBTABLE_H_INCLUDED

#include <string>
#include <list>
#include <utility>
#include <stdexcept>

/* If USE_HASH_MAP is defined, we will use the SGI hash_map extension.
 * Otherwise, we will use the STL map container, which is generally not
 * implemented as a hash table (in SGI's implementation, it uses a red-
 * black tree).
 *
 * g++, at least recent versions, uses SGI's STL implementation.  If you
 * are using GNU libstdc++ version 3, you will need to say USE_EXT_HASH_MAP,
 * which does the same thing as USE_HASH_MAP, but #includes <ext/hash_map>
 * instead.
 */
#include <map>
#include <vector>
#include <sstream>

// From https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR( x ) static_cast< std::ostringstream & >( \
            ( std::ostringstream() << std::dec << x ) ).str()

enum type_t {
	TY_BAD,
	TY_INT,
	TY_DOUBLE,
	TY_FUNC
};

class WrongNumberArguments : public std::logic_error
{
public:
    WrongNumberArguments(std::string name, int expected_num, int real_num)
        : logic_error(std::string("Expected ") + name + " to have " + SSTR(expected_num) + " args, got " + SSTR(real_num))
    {}
};

class ArgumentChecker{
  public:
    ArgumentChecker();
    ArgumentChecker(std::string fun_name, std::vector<type_t> arg_types_list);
    bool check_args(std::vector<type_t> arg_types_list);
  private:
    bool check_arg(int num, type_t t);
    int num_args;
    std::string fun_name;
    std::vector<type_t> arg_types;
};


// The values in a SymbolTable; accessed by string keys.
class Symbol {
    public:
	Symbol();
	Symbol(const std::string &name, type_t type = TY_BAD, int addr = -1);
  Symbol(const std::string &name, ArgumentChecker checker, int address = -1);

	// Accessors
	virtual const std::string &name() const;

	// Accessor and reference accessor for the type
	virtual type_t &type();
	virtual type_t type() const;
	
	// Accessor and reference accessor for the address
	virtual int &address();
	virtual int address() const;

	// Accessor and reference accessor for the address
	//virtual ArgumentChecker &checker();
	//virtual ArgumentChecker checker() const;

	// Comparison operators
	virtual bool operator<(const Symbol &s) const;
	virtual bool operator==(const Symbol &s) const;
	virtual bool operator!=(const Symbol &s) const;
  ArgumentChecker checkr;
    private:
	std::string nam;
	type_t typ;
	int addr;
};


class SymbolTable {
    protected:
	/* Associative array from std::string to such lists; see above for the
	 * meaning of USE_HASH_MAP */
	typedef std::map<std::string,Symbol> symtabsingle;
	typedef std::list<symtabsingle> symtabint;
    public:
	SymbolTable();
	SymbolTable(const SymbolTable &st);
	SymbolTable &operator=(const SymbolTable &st);

	Symbol *operator[](const std::string &s);
	const Symbol *operator[](const std::string &s) const;

	bool insert(Symbol s);
	bool exists(const std::string &s) const;

	int levelof(const std::string &s) const;

	// Number of variables in the top symbol table.
	int numvars() const;

	// Enter/leave a new scope.
	void enter();
	void leave();

    private:
	// The actual list of tables.
	symtabint hashes;
};

#endif // SYMBTABLE_H_INCLUDED
