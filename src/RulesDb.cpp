#include <algorithm>
#include <vector>
#include <iostream>
#include "RulesDb.h"
#include "Rule.h"

RulesDb::RulesDb():
_isAcopy(false)
{}

RulesDb::RulesDb(RulesDb const &other)
{
	this->_vRule = other._vRule;
	this->_isAcopy = true;
}

RulesDb::~RulesDb()
{
	std::vector<Rule *>::iterator it;

	if (!this->isEmpty() && !this->_isAcopy)
	{
		for (it = this->_vRule.begin(); it != this->_vRule.end(); ++it)
			delete (*it);
		this->_vRule.clear();
	}
}

void	RulesDb::appendRule(std::string const &str)
{
	size_t		 pos;
	Rule		*newRule;

	if (!str.empty())
	{
		std::string key(" THEN ");

		if ((pos = str.find(key)) == std::string::npos)
		{
			std::cout << "Error parsing cannot continue..." << std::endl;
			exit(EXIT_FAILURE);
		}
		newRule = new Rule(str.substr(0, pos), str.substr(pos + key.size()));
		this->_vRule.push_back(newRule);
	}
}

bool	RulesDb::isEmpty() const
{
	return (this->_vRule.empty());
}

std::vector<Rule *>	const &RulesDb::getRulesByGoal(std::string const &goal)
{
	std::vector<Rule *>::iterator it;

	if (!this->_findRules.empty())
		this->_findRules.clear();
	for (it = this->_vRule.begin(); it != this->_vRule.end(); ++it)
	{
		Rule	*rule = (*it);

		if (!rule->getGoal().compare(goal))
			this->_findRules.push_back(rule);
	}
	return (this->_findRules);
}

std::vector<Rule *>	const &RulesDb::getRules() const
{
	return (this->_vRule);
}
