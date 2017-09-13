#ifndef		KNOWLEDGEDB_H
#define		KNOWLEDGEDB_H

#include <string>
#include "RulesDb.h"
#include "FactsDb.h"

class	KnowledgeDb
{
public:
	KnowledgeDb(std::string const &fileName);
	~KnowledgeDb();

	bool						init();
	std::string const  &getGoal() const;
	RulesDb 	const  &getRulesDb() const;
	FactsDb	    const  &getFactsDb() const;

private:
	RulesDb		_rulesDb;
	FactsDb		_factsDb;
	std::string	_fileName,
						_goal;
};

#endif
