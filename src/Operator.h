#ifndef	OPERATOR_H
#define	OPERATOR_H

#include <vector>
#include "Atom.h"

class	Operator : public Atom
{
public:
	Operator();
	virtual ~Operator();

	virtual int	getState() = 0;
	virtual	void										setState(int) = 0;
	virtual	void	setName(std::string const &name) = 0;
	virtual	std::string	const &getName() const = 0;
	virtual	void										appendChild(Atom *child) = 0;
	virtual	void	setParent(Atom *parent) = 0;
	virtual	void	setFactsDb(FactsDb const &) = 0;
	virtual std::vector<Atom *>	const		&getChildren() const = 0;
};

#endif
