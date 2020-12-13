#include "Party.h"
#include "Citizen.h"
#include <iostream>
using namespace ELC;

Party::Party(char* name, Citizen* candidate)
{ 
	this->candidate = candidate;
	setPartyName(name); 
}

Party::Party()
{
	this->candidate = nullptr;
	setPartyName(nullptr);
}

Party::~Party()
{
	delete[] partyname;
}

bool Party::setPartyName(char* name)
{
	if (name == nullptr)
		partyname = nullptr;
	else
	{
		nameSize = strlen(name) + 1;
		strcpy(this->partyname, name);
	}
}

Party& Party::operator=(const Party& other)
{
	if (this != &other) {
		if (partyname != nullptr || (partyname != nullptr && nameSize != other.nameSize))
			delete[] partyname;

		nameSize = other.nameSize;
		partyname = new char[nameSize];
		strcpy(partyname, other.partyname);

		candidate = other.candidate;
		se_num = other.se_num;
		//replist
	}
	return *this;
}