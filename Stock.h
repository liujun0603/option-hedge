#ifndef STOCK_H
#define STOCK_H

#include"Asset.h"

class Stock :public Asset
{
public:

	Stock(std::vector<double> quote);
	Stock* clone() const;

private:

};

#endif
