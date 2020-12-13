#include "District.h"
#include "iostream"
using namespace ELC;

District::District(const char* disName, int numRep)
{
	bool check = set(disName, numRep);
	if (check != 1)
		std::cout << "Some error has occured with set" << std::endl;
	senum = NumOfCounties++;
	AlreadyVoted = 0;
}

District::District()
{
	District::set();
}

bool District::set()
{
	districtName = nullptr;
	repnum = 0;
	senum = -1;
	voted = 0;
	return 1;
}

District::~District()
{
	delete[] districtName;
}

bool District::set(const char* disName, int numRep)
{
	return (setDisName(disName) && setNumRep(numRep));
}

bool District::setDisName(const char* disName)
{

}

bool District::setNumRep(int numRep)
{
	repnum = numRep;
	if (repnum == numRep) return 1;
	else return 0;
}

int District::getNumRep() { return repnum; }

const char* District::getName() { return districtName; }