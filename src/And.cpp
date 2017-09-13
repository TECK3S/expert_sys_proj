#include <iostream>
#include "And.h"

And::And(): 
	Operator()
{
	this->setParent(NULL);
	this->setName("AND");
	this->setState(-5);
}

And::~And()
{}

int	And::getState()
{
	std::vector<Atom *>::iterator it;

	std::cout << "On AND atome, child number: " << this->_children.size() << std::endl;
	for (it = this->_children.begin(); it != this->_children.end(); ++it)
	{
		std::cout << "Step on AND atome, name = " << (*it)->getName() << std::endl;
		if ((*it)->getState() != 1)
			return (0);
	}
	return (1);
}

void	And::setName(std::string const &name)
{
	this->_name = name;
}

std::string	const &And::getName() const
{
	return (this->_name);
}

void	And::appendChild(Atom *child)
{
	this->_children.push_back(child);
}

void	And::setParent(Atom *parent)
{
	this->_parent = parent;
}

std::vector<Atom *>	const	&And::getChildren() const
{
	return (this->_children);
}

 void										And::setState(int state)
 {
	 this->_state = state;
 }

 
 void	And::setFactsDb(FactsDb const &factDb)
 {
	 this->_factDb = factDb;
 }
