#include <iostream>
#include "InfEngine.h"
#include "knowledgeDb.h"

int	main(int argc, char **argv)
{
  if (argc == 2)
    {
      KnowledgeDb	kdb(argv[1]);

      if (kdb.init())
	{
	  InfEngine		infEngine(kdb.getRulesDb(), kdb.getFactsDb());
			
	  infEngine.setGoal(kdb.getGoal());
	  infEngine.run();
	}
      else
	std::cout << "Cannot initialize knowledge data base, check input file." << std::endl;
    }
  else
    std::cout << "Usage :       ExpertSystem.exe + file path" << std::endl;
  // system("PAUSE");
  return (0);//EXIT_SUCCESS);
}
