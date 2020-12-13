#pragma once
#include "District.h"
class Citizen
{
	private:
		int ID;
		int birthYear;
		char* name;
		District& district;
		
	public:
		Citizen(char* name, int ID, int birthYear, District& district);

};

