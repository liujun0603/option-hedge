#include<iostream>
#include<fstream>
#include<string>
#include "DeltaHedge.h"
#include "StrategyConstructible.h"
#include "StrategyFactory.h"

using namespace std;

int main() {
	string strategyName;
	cout << "please choose the strategy you want to simulate"<<endl;
	cout << "DHRV for delta hedge using realized volatility" << endl;
	cout<<"DHIV for delta hedge using implied volatility"<<endl;
	cin >> strategyName;
	cout << "please enter hedge interval (1 or 2 is advised)" << endl;
	int hedgeInterval;
	cin >> hedgeInterval;

	vector<double> quoteOption = {0.088,0.084,0.079,0.063,0.076,0.074,0.075,0.067,0.066,0.063};
	vector<double> quoteStock = {2.349,2.351,2.361,2.367,2.345,2.343,2.335,2.348,2.356,2.367};
	double r, d, strike=2.35, expiry=0.5;
	cout << endl << "please enter risk free rate: ";
	cin >> r;
	cout << "please enter dividend rate: ";
	cin >> d;
	/*cout << "please enter strike of the option:";
	cin >> strike;
	cout << "please enter expiry of the option:"<<endl;
	cin >> expiry;*/
	cout << "strike of the option is: "<<strike<<endl;
	cout << "expiry of the option is: " <<expiry<< endl<<endl;
	const VanillaOption Option(quoteOption,expiry,strike,r,d,quoteStock);
	Stock stock(quoteStock);

	Statistics gatherer;
	ConvergenceTable gathererTwo(gatherer,1);
	Strategy* StrategyPtr = StrategyFactory::Instance().CreateStrategy(strategyName,Option,stock,r,d,hedgeInterval);

	if (StrategyPtr != NULL)
	{
		StrategyPtr->RecordPL(&gathererTwo);
		vector<vector<double>> results = gathererTwo.GetResultsSoFar();
		ofstream outfile("LOGBOOK.txt", ios_base::app);
		outfile << "\nFor "<<strategyName<<" P&L are \n";
		for (unsigned long i = 0; i < results.size(); i++)
		{
			for (unsigned long j = 0; j < results[i].size(); j++)
				outfile << results[i][j] << " ";
			outfile << "\n";
		}
		delete StrategyPtr;
		cout<<"the logbook can be found at local folder, named as LOGBOOK.txt";
	}

	double tmp;
	cin >> tmp;
	return 0;
}