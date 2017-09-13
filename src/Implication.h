#ifndef		IMPLICATION_H
#define	IMPLICATION_H

#include "Operator.h"

class	Implication : public Operator
{
public:
	Implication();
	~Implication();

	 int												getState();
	 void										setState(int);
	void											setName(std::string const &name);
	std::string	const						&getName() const;
	void											appendChild(Atom *child);
	void											setParent(Atom *parent);
	std::vector<Atom *>	const	&getChildren() const;
	void	setFactsDb(FactsDb const &);
};

#endif
