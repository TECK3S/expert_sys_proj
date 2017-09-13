#include <iostream>
#include "FactsDb.h"
#include "Fact.h"

FactsDb::FactsDb()
{}

FactsDb::~FactsDb()
{}

void	FactsDb::appendFacts(std::string const &name)
{
	if (!name.empty())
	{
		Fact	*fact;
		
		//fact = new Fact(name);
		std::cout << "Fact = " << name << std::endl;
		this->_lFacts.push_back(name);
	}
}

bool	FactsDb::isEmpty() const
{
	return (this->_lFacts.empty());
}

bool	FactsDb::exist(std::string const &name) const
{
	std::list<std::string>::const_iterator it;

	for (it = this->_lFacts.begin(); it != this->_lFacts.end(); ++it)
		if (!(*it).compare(name))
			return (true);
	return (false);
}
