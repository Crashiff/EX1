#include "PartyArray.h"
#include "Party.h"

PartyArray::PartyArray() { partyArray = nullptr, phySize = 0, logicSize = 0; }
PartyArray::~PartyArray() { if (partyArray != nullptr) delete[] partyArray; }

Party* PartyArray::getArray() { return partyArray; }
Party& PartyArray::getParty(int partyID) { return partyArray[partyID - 1]; }
int PartyArray::getPhySize() { return phySize; }
int PartyArray::getLogicSize() { return logicSize; }

bool PartyArray::setPhySize(int newMemSize) { phySize = newMemSize; return 1; }
bool PartyArray::setLogicSize(int newSize) { logicSize = newSize; return 1; }

void PartyArray::addParty(Party p)
{
	if (phySize == logicSize)
	{
		phySize *= 2;
		PartyArray::resize();
	}


	partyArray[logicSize] = p;
	logicSize++;
}

void PartyArray::resize()
{
	int i;
	Party* temp = new Party[phySize];
	for (i = 0; i < logicSize; i++)
		temp[i] = partyArray[i];

	delete[] partyArray;
	partyArray = temp;
}

