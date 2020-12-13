#pragma once
class CitizenList
{
	private:
		Citizen* citizenList;
	public:
		Citizen& getCitizen(int ID);
		void addCitizen(Citizen& c);
};

