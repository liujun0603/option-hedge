#ifndef ASSET_H
#define ASSET_H

#include<vector>

class Asset {
public:
	Asset(std::vector<double> quote);
	virtual Asset* clone() const=0;
	int GetQuoteNum();
	void UpdateIndex();
	int CurrentIndex() const;
	double CurrentQuote();
	double CurrentPosition();
	void SetPosition(double postion);
	virtual double CurrentValue();

private:
	mutable std::vector<double> _Quote;
	int _CurrentIndex;
	double _CurrentPosition;
};
 
#endif