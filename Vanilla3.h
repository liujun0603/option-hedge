//
//
//                   Vanilla3.h
//
//
#ifndef VANILLA_3_H
#define VANILLA_3_H

#include "wrapper.h"
#include "Asset.h"
#include<vector>

class VanillaOption:public Asset
{
public:

	VanillaOption(std::vector<double> quote,double Expiry,double Strike,double r,double d,std::vector<double> spotQuote);
	VanillaOption* clone() const;
	double BSValue(double Vol) const;
	double Vega(double Vol) const;
    double GetExpiry() const;
	double GetStrike() const;
	void SetExpiry(double expiry);

private:

	std::vector<double> _SpotQuote;
	double _Strike;
    double _Expiry;
	double _r;
	double _d;
};

#endif

