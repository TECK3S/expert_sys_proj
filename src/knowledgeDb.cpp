#include <fstream>
#include <iostream>
#include "knowledgeDb.h"

KnowledgeDb::KnowledgeDb(std::string const &fileName): 
	_fileName(fileName)
{}

KnowledgeDb::~KnowledgeDb()
{}

bool KnowledgeDb::init()
{
	std::ifstream file(this->_fileName.c_str(), std::ios::in);
	bool	state;

	if (!(state = file.is_open()))
		std::cout << "File cannot be open. Check the path." << std::endl;
	else
	{
		std::string	line, key("= "), search("? ");
		int	found;

		while (std::getline(file, line))
		{
			if (!line.empty() && !file.eof())
			{
				if ((found = line.find(key)) != std::string::npos)
				{
					line.erase(0, found + key.size());
					while ((found = line.find(',')) != std::string::npos) 
					{
						this->_factsDb.appendFacts(line.substr(0, found));
						line.erase(0, found + 1);
					}
					this->_factsDb.appendFacts(line);
				}
				else if ((found = line.find(search)) != std::string::npos)
					this->_goal.assign(&line[found + search.size()]);
				else
					this->_rulesDb.appendRule(line);
			}
		}
		file.close();
		if (this->_factsDb.isEmpty() || this->_rulesDb.isEmpty())
			state = false;
	}
	return (state);
}

std::string const &KnowledgeDb::getGoal() const
{
	return (this->_goal);
}

RulesDb	const &KnowledgeDb::getRulesDb() const
{
	return (this->_rulesDb);
}

FactsDb	const &KnowledgeDb::getFactsDb() const
{
	return (this->_factsDb);
}

