#include <iostream>
#include "Rule.h"

Rule::Rule(std::string const &premisse, std::string const &goal):
_premisse(premisse),
	_goal(goal)
{
	this->_voperator.push_back("AND");
	this->_voperator.push_back("THEN");
	this->extractFacts();
}

Rule::~Rule()
{
	this->_goal.clear();
	this->_premisse.clear();
}

std::string const &Rule::getPremisse() const
{
	return (this->_premisse);
}

std::string	const	&Rule::getOperator() const
{
	std::vector<std::string>::const_iterator	it;

	for (it = this->_voperator.begin(); it != this->_voperator.end(); ++it)
		if (this->_premisse.find((*it)) != std::string::npos)
			return (*it);
	return (this->_empty);
}

std::string const &Rule::getGoal() const
{
	return (this->_goal);
}

void	Rule::extractFacts()
{
	std::string cpy_premisse = this->_premisse;
	size_t	str_size = this->_voperator.at(0).size(),
				found;

	while ((found = cpy_premisse.find(this->_voperator.at(0))) != std::string::npos)
	{
		if (found - 1 >= 0)
			this->_vfact.push_back(cpy_premisse.substr(0, found - 1));
		cpy_premisse.erase(0, found + str_size + 1);
	}
	this->_vfact.push_back(cpy_premisse);
}

std::vector<std::string> const &Rule::getFacts() const
{
	return (this->_vfact);
}
