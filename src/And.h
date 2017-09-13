#ifndef	AND_H
#define	AND_H

#include <vector>
#include "Operator.h"

class	And : public Operator
{
public:
	And();
	~And();

	int												getState();
	void										       setState(int);
	void											setName(std::string const &name);
	std::string	const						&getName() const;
	void											appendChild(Atom *child);
	void											setParent(Atom *parent);
	std::vector<Atom *>	const	&getChildren() const;
	void	setFactsDb(FactsDb const &);
};

#endif
