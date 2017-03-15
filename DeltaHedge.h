#ifndef DELTAHEDGE_H
#define DELTAHEDGE_H

using namespace std;

#include"BlackScholesFormulas.h"
#include"Vanilla3.h"
#include"Stock.h"
#include"StatisticsMean.h"
#include"ConvergenceTable.h"

class Strategy {
public:
	Strategy(
		const wrapper<VanillaOption>& option,
		const wrapper<Stock>& stock,
		double r,
		double d,
		unsigned long interval);
	void RecordPL(ConvergenceTable* Gatherer);
	void SetVol(double volatility);
	virtual void GetVol() = 0;

protected:
	wrapper<VanillaOption> _Option;
	wrapper<Stock> _Stock;
	wrapper<StatisticsMean> _MeanSD;

private:
	double _r;
	double _d;
	double _Vol;
	unsigned long _interval;
};

#endif