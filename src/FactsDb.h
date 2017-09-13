#ifndef		FACTSDB_H
#define		FACTSDB_H

#include <string>
#include <list>

class	FactsDb
{
public:
	FactsDb();
	~FactsDb();

	void	appendFacts(std::string const &fact);
	bool	isEmpty() const;
	bool exist(std::string const &name) const;

private:
	std::list<std::string> _lFacts;
};


#endif
