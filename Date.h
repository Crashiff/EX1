#pragma once
#include <iostream>
using namespace std;
class Date
{
	private:
		int year, month, day;
		
	public:
		bool setDate(int year, int month, int day);
		Date(int year, int month, int day);
		Date();
		friend ostream& operator<<(ostream& os, const Date& date)
		{
			os << "The date for the election is: " << date.day << '.' << date.month << '.' << date.year << endl;
			return os;
		}
};

