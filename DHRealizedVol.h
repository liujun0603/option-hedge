#ifndef DHREALIZEDVOL_H
#define DHREALIZEDVOL_H

#include"DeltaHedge.h"

class DHRealizedVol :public Strategy {

public:
	DHRealizedVol(const wrapper<VanillaOption>& option,const wrapper<Stock>& stock,double r,double d,unsigned long interval);
	void GetVol();
private:

};

#endif