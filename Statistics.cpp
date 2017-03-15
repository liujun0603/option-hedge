#include"Statistics.h"

using namespace std;

Statistics::Statistics()
	:_IndexDone(0UL)
{
}

void Statistics::DumpOneResult(double result)
{
	_IndexDone++;
	_CurrentResult = result;
}

vector<vector<double>> Statistics::GetResultsSoFar() const
{
	vector<vector<double>> Results(1);

	Results[0].resize(1);
	Results[0][0] = _CurrentResult;

	return Results;
}

Statistics* Statistics::clone() const
{
	return new Statistics(*this);
}