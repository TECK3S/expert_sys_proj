#ifndef		INFENGINE_H
#define	INFENGINE_H

#include "RulesDb.h"
#include "FactsDb.h"

class	Atom;

class	InfEngine
{
public:
	InfEngine(RulesDb const &, FactsDb const &);
	~InfEngine();

	void				setGoal(std::string const &goal);
	void				run();
	void				buildTrees();
	void				createAtom(Rule *rule, Atom *atom = NULL);
	void				createAtomEx(Rule *rule, Atom *atom);
	Atom*			isAtomExists(std::string const &name) const;

private:
	RulesDb		_rulesDb;
	FactsDb		_factsDb;
	std::string	 _goal;
	Atom			*_root;
	std::vector<Atom *> _vAtoms;
};

#endif

