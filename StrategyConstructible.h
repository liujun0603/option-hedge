//
//
//                       StrategyConstructible.h
//
//

#ifndef STRATEGY_CONSTRUCTIBLE_H
#define STRATEGY_CONSTRUCTIBLE_H


#include <iostream>

#include "StrategyFactory.h"
#include <string>

//for each Strategy class, we declare a global variable of StrategyHelper<kind of Strategy>
// , which create the function that can return *Strategy and the pointer to the function
// , and registers the Strategy class with our factory
// (all global variables are intialized when the program begins before anything)

//get each Strategy class to communicate with the factory
// , without explicitly calling anything from the main routine

template <class T>
class StrategyHelper
{
public:
	StrategyHelper(std::string);
	//static: should not be associated with any particular object
	static Strategy* Create(const wrapper<VanillaOption>&,const wrapper<Stock>&,double,double,unsigned long);
};

template <class T>
Strategy* StrategyHelper<T>::Create(const wrapper<VanillaOption>& Option,const wrapper<Stock>& Stock,double r,double d,unsigned long interval)
{
	return new T(Option,Stock,r,d,interval);
}

template <class T>
StrategyHelper<T>::StrategyHelper(std::string id)
{
	StrategyFactory& theStrategyFactory = StrategyFactory::Instance();
	theStrategyFactory.RegisterStrategy(id, StrategyHelper<T>::Create);
}

#endif