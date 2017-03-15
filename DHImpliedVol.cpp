#include"DHImpliedVol.h"
#include<iostream>

DHImpliedVol::DHImpliedVol(
	const wrapper<VanillaOption>& option,
	const wrapper<Stock>& stock,
	double r,
	double d,
	unsigned long interval)
	:Strategy(option,stock,r,d,interval)
{
}

void DHImpliedVol::GetVol() {
	double vol = NewtonRaphson<VanillaOption,&VanillaOption::BSValue,&VanillaOption::Vega>
			(_Option->CurrentQuote(),
			_MeanSD->GetResultsSoFar()[0][1],
			0.001,
			*_Option);
	SetVol(vol);
}