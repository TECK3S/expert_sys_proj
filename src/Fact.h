#ifndef		FACT_H
#define	FACT_H

#include <string>
#include "Atom.h"

class	Fact : public Atom
{
public:
	Fact(std::string const &name);
	~Fact();

	 int												getState();
	 void											setState(int state);
	void											setName(std::string const &name);
	std::string	const						&getName() const;
	void											appendChild(Atom *child);
	void											setParent(Atom *parent);
	std::vector<Atom *>	const	&getChildren() const;
	void	setFactsDb(FactsDb const &);
};

#endif
