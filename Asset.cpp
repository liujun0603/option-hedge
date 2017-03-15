#include"Asset.h"

Asset::Asset(std::vector<double> quote)
	:_Quote(quote)
{
	_CurrentIndex = -1;
	_CurrentPosition = 0;
}

int Asset::GetQuoteNum() {
	return _Quote.size();
}

void Asset::UpdateIndex() {
	_CurrentIndex++;
}

int Asset::CurrentIndex() const{
	return _CurrentIndex;
}

double Asset::CurrentQuote() {
	return _Quote[_CurrentIndex];
}

double Asset::CurrentPosition() {
	return _CurrentPosition;
}

void Asset::SetPosition(double position) {
	_CurrentPosition = position;
}

double Asset::CurrentValue() {
	return _CurrentPosition*CurrentQuote();
}