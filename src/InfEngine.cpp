#include <vector>
#include "Rule.h"
#include "Operator.h"
#include "InfEngine.h"
#include "Fact.h"
#include "And.h"
#include "Implication.h"

InfEngine::InfEngine(RulesDb const &rulesDb, FactsDb const &factsDb):
_rulesDb(rulesDb),
	_factsDb(factsDb),
	_goal(""),
	_root(NULL)
{}

InfEngine::~InfEngine()
{}

void InfEngine::setGoal(std::string const &goal)
{
	this->_goal = goal;
}

void InfEngine::run()
{
	int	i;
	std::vector<Atom *>::iterator it;

	this->buildTrees();
	if (!this->_vAtoms.empty())
	{
		for (it = this->_vAtoms.begin(); it != this->_vAtoms.end(); ++it)
			std::cout << (*it)->getName() << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		i = this->_vAtoms.at(0)->getState();
		std::cout << i << std::endl;
	}
}

void	InfEngine::createAtom(Rule *rule, Atom *pAtom)
{
	Atom				*atom, *tmp;
	Operator		*op;

	if (!pAtom)
	{
		atom = new Fact(rule->getGoal());
		this->_vAtoms.push_back(atom);
	}
	else
		atom = pAtom;
	if (rule->getOperator().empty()) // si Opérateur d'IMPLICATION
	{
		std::vector<std::string> vFacts;

		vFacts = rule->getFacts();
		op = new Implication;
		if (!vFacts.empty())
		{
			tmp = new Fact(vFacts[0]);
			tmp->setFactsDb(this->_factsDb);
			tmp->setParent(op);
			op->appendChild(tmp);
			this->_vAtoms.push_back(tmp);
		}
	}
	else //Opérateur AND
	{
		std::vector<std::string> vFacts;
		std::vector<std::string>::iterator itFacts;

		op = new And;
		vFacts = rule->getFacts();
		for (itFacts = vFacts.begin(); itFacts != vFacts.end(); ++itFacts)
		{
			tmp = new Fact((*itFacts));
			tmp->setFactsDb(this->_factsDb);
			tmp->setParent(op);
			op->appendChild(tmp);
			this->_vAtoms.push_back(tmp);
		}
	}
	op->setParent(atom);
	atom->appendChild(op);
}

void	InfEngine::createAtomEx(Rule *rule, Atom *atom)
{
	Atom	 *parent, *tmp;
	std::vector<Atom *> vAtom;

	vAtom = atom->getChildren();
	if (rule->getOperator().empty()) //Operateur THEN
	{
		std::vector<Atom *>::iterator it;

		if (!vAtom.empty()) // Pointeur sur l'opérateur d'implication
		{
			parent = vAtom[0];
			if (!rule->getFacts().empty())
			{
				tmp = new Fact(rule->getFacts().at(0));
				tmp->setFactsDb(this->_factsDb);
				tmp->setParent(parent);
				parent->appendChild(tmp);
				this->_vAtoms.push_back(tmp);
			}
		}
		else
			this->createAtom(rule, atom);
	}
	else
	{
		std::vector<std::string> vFacts;
		std::vector<std::string>::iterator itFacts;
		Operator		*op;

		if (!vAtom.empty()) // Pointeur sur l'opérateur AND existant
			op = dynamic_cast<Operator *> (vAtom[0]);
		else
		{
			op = new And;
			op->setParent(atom);
			atom->appendChild(op);
		}
		vFacts = rule->getFacts();
		for (itFacts = vFacts.begin(); itFacts != vFacts.end(); ++itFacts)
		{
			tmp = new Fact((*itFacts));
			tmp->setFactsDb(this->_factsDb);
			tmp->setParent(op);
			op->appendChild(tmp);
			this->_vAtoms.push_back(tmp);
		}
	}
}

void InfEngine::buildTrees()
{
	std::vector<Rule *> vRules;
	std::vector<Rule *>::iterator itRules;

	vRules = this->_rulesDb.getRules();
	for (itRules = vRules.begin(); itRules != vRules.end(); ++itRules)
	{
		Rule				*rule;
		Atom				*atom;

		rule = (*itRules);
		if (!(atom = this->isAtomExists(rule->getGoal()))) // Si l'atome n'existe pas
			this->createAtom(rule);
		else
			this->createAtomEx(rule, atom);
	}
}

Atom* InfEngine::isAtomExists(std::string const &name) const
{
	std::vector<Atom *>::const_iterator it;

	for (it = this->_vAtoms.begin(); it != this->_vAtoms.end(); ++it)
	{
		Atom	*atom;

		atom = (*it);
		if (!atom->getName().compare(name))
			return (atom);
	}
	return (NULL);
}
