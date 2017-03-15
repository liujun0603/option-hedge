#include"DeltaHedge.h"
#include"BlackScholesFormulas.h"
#include<iostream>
#include<fstream>

Strategy::Strategy(
	const wrapper<VanillaOption>& option,
	const wrapper<Stock>& stock,
	double r,
	double d,
	unsigned long interval)
	:_Option(option), _Stock(stock), _r(r), _d(d),_interval(interval)
{
	_Vol = 0.1;
	_MeanSD=StatisticsMean();
}

void Strategy::RecordPL(ConvergenceTable* Gatherer) {
	ofstream outfile("LOGBOOK.txt", ios_base::app);
	_Option->SetPosition(-1);
	double cash = 0;
	for (int i = 0; i < _Stock->GetQuoteNum(); i++) {
		//update expiry
		_Option->UpdateIndex();
		_Stock->UpdateIndex();
		_MeanSD->DumpOneResult(_Stock->CurrentQuote());

		if (i%_interval == 0) {
			GetVol();
			double delta = BlackScholesCallDelta(
				_Stock->CurrentQuote(),
				_Option->GetStrike(),
				_r,
				_d,
				_Vol,
				_Option->GetExpiry()
				);
			double preStockPosition = _Stock->CurrentPosition();
			_Stock->SetPosition(delta);
			double netPosition = 0;
			if (i == 0)
				netPosition = -1 * (_Option->CurrentValue() + _Stock->CurrentValue());
			else
				netPosition = (preStockPosition - _Stock->CurrentPosition())*_Stock->CurrentQuote();
			cash += netPosition;
		}
		outfile << " current value for option is " << _Option->CurrentValue() << endl;
		outfile << " current position for stock is " << _Stock->CurrentPosition() << endl;
		outfile << " current value for stock is " << _Stock->CurrentValue() << endl;
		outfile << " current value for cash is " << cash << endl<<endl;
		Gatherer->DumpOneResult(_Option->CurrentValue()+_Stock->CurrentValue()+cash);
	}
}

void Strategy::SetVol(double vol) {
	_Vol = vol;
	/*cout << "the current volatility is " << vol<<endl;*/
}