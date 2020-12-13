#pragma once
#include "Date.h"
#include "CitizenList.h"
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
	CitizenList& getCitizenList();
	PartyArray& getPartyArray();

};

