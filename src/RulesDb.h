#ifndef		RULESDB_H
#define		RULESDB_H

#include <string>
#include <vector>
#include <iostream>

class	Rule;

class	RulesDb
{
public:
	RulesDb();
	~RulesDb();
	RulesDb(RulesDb const &other);

	void	appendRule(std::string const &str);
	bool	isEmpty() const;
	std::vector<Rule *>	const &getRules() const;
	std::vector<Rule *>	const &getRulesByGoal(std::string const &goal);

private:
	std::vector<Rule *> _vRule,
									_findRules;
	bool							_isAcopy;
};

#endif
