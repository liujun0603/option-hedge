#ifndef DHIMPLIEDVOL_H
#define DHIMPLIEDVOL_H

#include"DeltaHedge.h"
#include"NewtonRaphson.h"

class DHImpliedVol:public Strategy{
	
public:		
	DHImpliedVol(const wrapper<VanillaOption>& option,
		const wrapper<Stock>& stock,
		double r,
		double d,
		unsigned long interval);
	void GetVol();
private:

};

#endif