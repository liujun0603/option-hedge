
#include"DHImpliedVol.h"
#include"DHRealizedVol.h"
#include "StrategyConstructible.h"

//the variables are in an unknown namespace
// and out of the sight of the rest of the program
// both global and invisible
// only purpose is do registration
namespace
{
	StrategyHelper<DHImpliedVol> RegisterDHImpliedVol("DHIV");

	StrategyHelper<DHRealizedVol> RegisterDHRealizedVol("DHRV");
}



