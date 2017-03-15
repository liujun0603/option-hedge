//
//
//                  Vanilla3.cpp
//
//
#include "Vanilla3.h"
#include"BlackScholesFormulas.h"

VanillaOption::VanillaOption(std::vector<double> quote,double Expiry,double Strike,double r,double d,std::vector<double> spotQuote)
                               : Asset(quote), _Expiry(Expiry),_Strike(Strike),_r(r),_d(d),_SpotQuote(spotQuote)
{
}

VanillaOption* VanillaOption::clone() const{
	return new VanillaOption(*this);
}

double VanillaOption::GetExpiry() const
{
    return _Expiry;
}

double VanillaOption::GetStrike() const {
	return _Strike;
}

void VanillaOption::SetExpiry(double expiry) {
	_Expiry = expiry;
}


double VanillaOption::BSValue(double Vol) const{
	return BlackScholesCallVega(_SpotQuote[CurrentIndex()], _Strike, _r, _d, Vol, _Expiry);
}

double VanillaOption::Vega(double Vol) const{
	return BlackScholesCallVega(_SpotQuote[CurrentIndex()],_Strike,_r,_d,Vol,_Expiry);
}
