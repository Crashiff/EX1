#pragma once
#include "Date.h"
#include "Registry.h"
#include "partyArray.h"
#include "DistrictArray.h"

class Election
{
private:
	Date date;
	DistrictArray districtArr;
	Registry citizenList;
	PartyArray partyArr;

public:
	Election();

	Date& getDate();
	DistrictArray& getDistrictArray();
	Registry& getCitizenList();
	PartyArray& getPartyArray();

};

