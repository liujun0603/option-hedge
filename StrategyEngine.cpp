
#include "StrategyEngine.h"
#include <cmath>

StrategyEngine::StrategyEngine(const wrapper<Strategy>& TheStrategy,
	const Parameters& r)
	:
	_TheStrategy(TheStrategy),
	_r(r),
{
	_TheseCashFlows.resize(TheProduct->MaxNumberOfCashFlows());
}

double StrategyEngine::DoOnePath(const MJArray& SpotValues) const
{
	unsigned long NumberFlows = _TheProduct->CashFlows(SpotValues, _TheseCashFlows);
	double Value = 0.0;

	for (unsigned i = 0; i < NumberFlows; ++i)
		Value += _TheseCashFlows[i]._Amount * _Discounts[_TheseCashFlows[i]._TimeIndex];

	return Value;
}

double StrategyEngine::StrategyPL(const path& path) {
	Size n = path.length() - 1;
	QL_REQUIRE(n>0, "the path cannot be empty");

}

void ExoticEngine::DoSimulation(Statistics* TheGatherer, unsigned long NumberOfPaths)
{
	MJArray SpotValues(_TheProduct->GetLookAtTimes().size());

	_TheseCashFlows.resize(_TheProduct->MaxNumberOfCashFlows());
	double thisValue;

	for (unsigned long i = 0; i < NumberOfPaths; ++i)
	{
		GetOnePath(SpotValues);
		thisValue = DoOnePath(SpotValues);
		TheGatherer->DumpOneResult(thisValue);
	}

	return;
}