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
	TY_FUNC,
  TY_STR
};

std::string type_id_to_str(type_t type_id);

class WrongNumberArguments : public std::logic_error
{
public:
    WrongNumberArguments(std::string name, int expected_num, int real_num)
        : logic_error(std::string("Expected ") + name + " to have " + SSTR(expected_num) + " args, got " + SSTR(real_num))
    {}
};

class WrongArgumentType : public std::logic_error
{
public:
    WrongArgumentType(std::string name, int arg_num, type_t expected_type, type_t real_type)
        : logic_error(std::string("Expected ") + name + " argument " + SSTR(arg_num + 1) + " to be of type " + type_id_to_str(expected_type) + ", got " + type_id_to_str(real_type))
    {}
};

class WrongReturnType : public std::logic_error
{
public:
    WrongReturnType(std::string name, type_t expected_type, type_t real_type)
        : logic_error(std::string("Expected return value for ") + name + " to be of type " + type_id_to_str(expected_type) + ", got " + type_id_to_str(real_type))
    {}
};

class WrongAssignmentType : public std::logic_error
{
public:
    WrongAssignmentType(std::string name, type_t expected_type, type_t real_type)
        : logic_error(std::string("Expected ") + name + " to be assigned value of type " + type_id_to_str(expected_type) + ", got " + type_id_to_str(real_type))
    {}
};

class MixedTypes : public std::logic_error
{
public:
    MixedTypes(std::string op_name, type_t expected_type, type_t real_type)
        : logic_error(std::string("Operation '") + op_name + "' cannot mix types " + type_id_to_str(expected_type) + " and " + type_id_to_str(real_type))
    {}
};

class ArgumentChecker{
  public:
    ArgumentChecker();
    ArgumentChecker(std::string function_name, std::vector<type_t> arg_types_list, type_t ret_val_type);
    bool check_args(std::vector<type_t> arg_types_list);
    bool check_return(type_t given_ret_val_type);
    void set_fun_name();
  private:
    bool check_arg(int num, type_t t);
    int num_args;
    std::string fun_name;
    std::vector<type_t> arg_types;
    type_t return_value_type;
};


// The values in a SymbolTable; accessed by string keys.
class Symbol {
    public:
	Symbol();
	Symbol(const std::string &name, type_t type = TY_BAD, int addr = -1);
  Symbol(const std::string &name, std::vector<type_t> expected_arg_types, int address = -1, type_t ret_val_type = TY_INT);
  Symbol(const std::string &name, int address = -1);

  virtual void set_function_type_info(std::vector<type_t> expected_arg_types, type_t ret_val_type = TY_INT);

	// Accessors
	virtual const std::string &name() const;

	// Accessor and reference accessor for the type
	virtual type_t &type();
	virtual type_t type() const;
	
	// Accessor and reference accessor for the address
	virtual int &address();
	virtual int address() const;

	// Comparison operators
	virtual bool operator<(const Symbol &s) const;
	virtual bool operator==(const Symbol &s) const;
	virtual bool operator!=(const Symbol &s) const;
  virtual bool check_args(std::vector<type_t> arg_types_list);
  virtual bool check_return(type_t given_ret_val_type);
	type_t return_type;
    private:
  ArgumentChecker checker;
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
