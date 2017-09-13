#ifndef	ATOM_H
#define	ATOM_H

#include <string>
#include <vector>
#include "FactsDb.h"

class	Atom
{
public:
	Atom();
	virtual ~Atom();

	virtual int										getState() = 0;
	virtual	void										setState(int) = 0;
	virtual	void										setName(std::string const &name) = 0;
	virtual	std::string	const				&getName() const = 0;
	virtual	void										appendChild(Atom *child) = 0;
	virtual	void										setParent(Atom *parent) = 0;
	virtual std::vector<Atom *>	const		&getChildren() const = 0;
	virtual	void										setFactsDb(FactsDb const &) = 0;

protected:
	Atom							*_parent;
	std::string					  _name;
	int								_state;
	std::vector<Atom *> _children;
	FactsDb					_factDb;
};


#endif
