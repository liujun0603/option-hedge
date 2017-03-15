#include "StrategyFactory.h"
#include <iostream>
using namespace std;

void StrategyFactory::RegisterStrategy(string StrategyId,CreateStrategyFunction CreatorFunction)
{
	TheCreatorFunctions.insert(pair<string,CreateStrategyFunction>(StrategyId,CreatorFunction));
}

//return type is Strategy*: possible to return a null pointer
Strategy* StrategyFactory::CreateStrategy(string StrategyId,
	const wrapper<VanillaOption>& vanillaOption,
	const wrapper<Stock>& stock,
	double r,
	double d,
	unsigned long interval)
{
	map<string, CreateStrategyFunction>::const_iterator i = TheCreatorFunctions.find(StrategyId);

	if (i == TheCreatorFunctions.end())
	{
		std::cout << StrategyId << " is an unknown Strategy" << std::endl;
		return NULL;
	}

	return (i->second)(vanillaOption,stock,r,d,interval);
}

StrategyFactory& StrategyFactory::Instance()
{
	//static: on the first call (refer) to instance(), the theFactory object 
	// exists until the end of the program
	// (StrategyFactory cannot be global
	// for we cannot control it be created before other global variable
	// , which will refer to StrategyFactory)
	//singleton pattern: there must be only one copy of StrategyFactory
	static StrategyFactory theFactory;
	return theFactory;
}
