#pragma once
#include "Party.h"
using namespace ELC;
class PartyArray
{

	private:
		Party* partyArray;
		int phySize, logicSize;
		void resize();

	public:
		PartyArray();
		~PartyArray();

		Party* getArray();
		Party& getParty(int partyID);
		int getPhySize();
		int getLogicSize();

		bool setPhySize(int newMemSize);
		bool setLogicSize(int newSize);

		void addParty(Party p); /*p is NOT to be received as reference as it is a local variable*/
		



};

