#include"Stock.h"

Stock::Stock(std::vector<double> quote)
	:Asset(quote)
{}

Stock* Stock::clone() const{
	return new Stock(*this);
}