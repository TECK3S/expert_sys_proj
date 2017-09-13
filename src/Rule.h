#ifndef		RULE_H
#define	RULE_H

#include <vector>
#include <string>

class	Rule
{
public:
	Rule(std::string const &premisse, std::string const &goal);
	~Rule();

	std::string const								&getPremisse() const;
	std::string const								&getOperator() const;
	std::string const								&getGoal() const;
	std::vector<std::string> const		&getFacts() const;

private:
	void	extractFacts();

	std::string		_premisse,
							_goal,
							_empty;
	std::vector<std::string> _voperator,
										  _vfact;
};

#endif

