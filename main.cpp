#include <iostream>
#include "District.h"
#include "Election.h"
#include "Citizen.h"
#include "PartyArray.h"
#include "Party.h"
using namespace std;
using namespace ELC;

void addDistrict(Election& round)
{
	char name[1000];
	int numRep;
	cout << "Please enter district name: " << endl;
	cin >> name;
	cout << "Please enter the number of representitives: " << endl;
	cin >> numRep;

	DistrictArray& arr = round.getDistrictArray();
	District* d = new District(name, numRep);
	arr.addDistrict(d);
}

void addCitizen(Election& round)
{
	char name[1000];
	int ID, birthYear, districtID;
	cout << "Please enter citizen name: " << endl;
	cin >> name;
	cout << "Please enter the citizen's ID: " << endl;
	cin >> ID;
	cout << "Please enter the citizen's birthYear: " << endl;
	cin >> birthYear;
	cout << "Please enter the citizen's district ID: " << endl;
	cin >> districtID;

	DistrictArray arr = round.getDistrictArray();
	if (!(0 < districtID && districtID <= arr.size)) /*If district ID is NOT in correct range - fail and return*/
	{
		cout << "District doesn't exist, citizen addition failed" << endl;
		return;
	}

	Registery reg = round.getCitizenList();
	reg.add(Citizen(name, ID, birthYear, districtID)); 
}

void addParty(Election& round)
{
	char name[1000];
	int candidateID;
	cout << "Please enter the party's name: " << endl;
	cin >> name;
	cout << "Please enter the ID of the candidate for head of state: " << endl;
	cin >> candidateID;

	PartyArray arr = round.getPartyArray();
	arr.add(Party(name, candidateID)); /*to be received as reference*/
}

void addCitizenAsRep(Election& round)
{
	int ID, PartyID, districtID;
	cout << "Please enter the candidate's ID: " << endl;
	cin >> ID;
	cout << "Please enter the party's number: " << endl;
	cin >> PartyID;
	cout << "Please enter the district's number: " << endl;
	cin >> districtID;
	
	Registery& citizenList = round.getCitizenList();
	PartyArray& partyArr = round.getPartyArray();
	DistrictArray& distArr = round.getDistrictArray();

	Citizen& c = citizenList.findCit(ID);
	Party& p = partyArr.party[PartyID - 1]; /*party is an array of parties, PartyID is also used as index (-1 for 0)*/
	District& d = distArr.district[districtID - 1] ;

	/*Add citizen to party, to the correct list with districtID*/
	p.districtsRepsListsArray[districtID].add(c, d);
}

void showAllDistricts(Election& round)
{
	int i;

	DistrictArray arr = round.getDistrictArray();
	for (i = 0; i < arr.size; i++)
		cout << arr.district[i] << endl;
}

void showAllCitizens(Election& round)
{
	Registery& CitizenList = round.getCitizenList();
	cout << CitizenList << endl; /*Print by ID also possible - used in inner implementation*/
}

void showAllParties(Election& round)
{
	int PartyID;

	PartyArray& arr = round.getPartyArray();
	for (PartyID = 0; PartyID < arr.size; PartyID++)
		cout << arr.party[PartyID] << endl;
}

void vote(Election& round)
{
	int ID, PartyID;
	cout << "Please enter the voter's ID: " << endl;
	cin >> ID;
	cout << "Please enter the voter's party ID: " << endl;
	cin >> PartyID;

	Registery& citizenList = round.getCitizenList();
	PartyArray& arr = round.getPartyArray();

	Citizen& c = citizenList.find(ID);
	Party& p = arr.party[PartyID - 1];
	p.vote(c); /*Try to vote, if unsuccesful - tell user*/
}

void showVotingRes()
{
	
}

void exitFunc()
{
	/*Might be unnecessary*/
	cout << "This voting round has finished, program will now exit" << endl;
}


/***************************************************************/
/**************THE MAIN MENU AND MAIN FUNCTION******************/
/***************************************************************/
void mainMenu(Election& round)
{
	cout << "1. Add district" << endl;
	cout << "2. Add citizen" << endl;
	cout << "3. Add party" << endl;
	cout << "4. Add citizen as party representetive" << endl;
	cout << "5. Show all districts" << endl;
	cout << "6. Show all citizens" << endl;
	cout << "7. Show all parties" << endl;
	cout << "8. Vote" << endl;
	cout << "9. Show voting results" << endl;
	cout << "10. Exit program" << endl;

	while (true)
	{
		int op;
		cin >> op;

		switch (op)
		{
			case 1: addDistrict(round); break;
			case 2: addCitizen(round); break;
			case 3: addParty(round); break;
			case 4: addCitizenAsRep(round); break;
			case 5: showAllDistricts(round); break;
			case 6: showAllCitizens(round); break;
			case 7: showAllParties(round); break;
			case 8: vote(); break;
			case 9: showVotingRes(); break;
			case 10: exitFunc(); return;

			/*Bad input massage as default for anything else*/
			default: cout << "You tried to enter an invalid number for an operation" << endl;
		}
	}
}

int main()
{
	Election round;
	Date& date = round.getDate();
	date.setDate(2020, 03, 16);
	cout << round.getDate() << endl;

	mainMenu(round);
	cout << "Good afternoon, good evening and good night" << endl;
}