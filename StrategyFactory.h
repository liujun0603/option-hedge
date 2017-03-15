//factory pattern: allow us to add new Strategys
// without explicitly calling the new type in main function
#ifndef STRATEGYFACTORY_H
#define STRATEGYFACTORY_H

#include <map>
#include <string>
#include"DHImpliedVol.h"
#include"DHRealizedVol.h"

class StrategyFactory
{
public:

	typedef Strategy* (*CreateStrategyFunction)(const wrapper<VanillaOption>&,const wrapper<Stock>& stock,double,double,unsigned long);

	//static: the function needn't to be called dependent on an existing object
	static StrategyFactory& Instance();
	void RegisterStrategy(std::string, CreateStrategyFunction);
	Strategy* CreateStrategy(std::string StrategyId,
		const wrapper<VanillaOption>& vanillaOption,
		const wrapper<Stock>& stock,
		double r,
		double d,
		unsigned long interval);
	~StrategyFactory() {};

private:
	std::map<std::string,CreateStrategyFunction> TheCreatorFunctions;
	//singleton pattern, but can be called by instance()
	StrategyFactory() {}
	StrategyFactory(const StrategyFactory&) {}
	StrategyFactory& operator=(const StrategyFactory&) { return *this; }
};

#endif