#include "Date.h"

bool Date::setDate(int year, int month, int day) 
{
	this->year = year, this->month = month, this->day = day;
	if(this->year == year, this->month == month, this->day == day)
		return true;
	else
	{
		cout << "setting date failed" << endl;
		return false;
	}
}

Date::Date(int year, int month, int day) { setDate(year, month, day); }
Date::Date() { setDate(0, 0, 0); } /*Used as default, can be used to check if a date was set*/