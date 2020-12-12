#include "Election.h"
using namespace ELC;

Date& Election::getDate() { return date; }

Election::Election()
{
	Date date();
	DistrictArray districtArr();
	Registry citizenList;
	PartyArray partyArr;
}

DistrictArray& Election::getDistrictArray() { return districtArr; }
