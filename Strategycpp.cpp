#include"Strategy.h"
#include"BlackScholesFormulas.h"

Strategy::Strategy(
	const wrapper<VanillaOption>& vanillaOption,
	const wrapper<Stock>& stock,
	double r,
	double d)
	:_VanillaOption(vanillaOption), _Stock(stock), _r(r), _d(d)
{
}