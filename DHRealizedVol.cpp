#include"DHRealizedVol.h"
#include<iostream>


DHRealizedVol::DHRealizedVol(
	const wrapper<VanillaOption>& option,
	const wrapper<Stock>& stock,
	double r,
	double d,
	unsigned long interval)
	: Strategy(option,stock,r,d,interval)
{
}

void DHRealizedVol::GetVol() {
	double vol = _MeanSD->GetResultsSoFar()[0][1];
	SetVol(vol);
}