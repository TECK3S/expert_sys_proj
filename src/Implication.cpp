#include <iostream>
#include "Implication.h"

Implication::Implication():
	Operator()
{
	this->setParent(NULL);
	this->setName("IMPLICATION");
}

Implication::~Implication()
{}

 int	Implication::getState()
 {
	 std::vector<Atom *>::iterator it;

	 std::cout << "On implication atome, children number: " << this->_children.size() << std::endl;
	 for (it= this->_children.begin(); it != this->_children.end(); ++it)
	 {
		  std::cout << "Step implication atome, name = " <<  (*it)->getName() << std::endl;
		 if ((*it)->getState() == 1)
			 return (1);
	 }
	 return (0);
 }

 void	Implication::setName(std::string const &name)
{
	this->_name = name;
}

std::string	const &Implication::getName() const
{
	return (this->_name);
}

void	Implication::appendChild(Atom *child)
{
	this->_children.push_back(child);
}

void	Implication::setParent(Atom *parent)
{
	this->_parent = parent;
}

std::vector<Atom *>	const	&Implication::getChildren() const
{
	return (this->_children);
}

 void										Implication::setState(int state)
 {
	 this->_state = state;
 }

 void	Implication::setFactsDb(FactsDb const &factDb)
 {
	 this->_factDb = factDb;
 }
