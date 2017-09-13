#include <iostream>
#include "Fact.h"

Fact::Fact(std::string const &name):
	Atom()
{
	this->setParent(NULL);
	this->setName(name);
	this->setState(-5);
}

Fact::~Fact()
{}

 int	Fact::getState()
 {
	 std::vector<Atom *>::iterator it;
	int	result = 0;

	std::cout << "On FACT atome, name = " << this->_name <<  " children number = " << this->_children.size() << std::endl;
	if (!this->_children.empty())
	{
		for (it = this->_children.begin(); it != this->_children.end(); ++it)
		{
			std::cout << "setp On fact atome " << this->_name << std::endl;
			result = (*it)->getState();
			std::cout << "Result : " << result << std::endl;
			if (result == 0)
				break;
		}
	}
	else
	{
		if (this->_factDb.exist(this->getName()))
			return (1);
	}
	if (this->_factDb.exist(this->getName()))
		return (1);
	return (result);
 }

 void	Fact::setState(int state)
 {
	 this->_state = state;
 }

 void	Fact::setName(std::string const &name)
{
	this->_name = name;
}

std::string	const &Fact::getName() const
{
	return (this->_name);
}

void	Fact::appendChild(Atom *child)
{
	this->_children.push_back(child);
}

void	Fact::setParent(Atom *parent)
{
	this->_parent = parent;
}

std::vector<Atom *>	const	&Fact::getChildren() const
{
	return (this->_children);
}


 void	Fact::setFactsDb(FactsDb const &factDb)
 {
	 this->_factDb = factDb;
 }
