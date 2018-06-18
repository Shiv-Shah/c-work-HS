#pragma once
#include <iostream>
#include <string>
#include <ostream>
#include<istream>
#include "30.1.h"

using namespace std;

class days
{
public:

	int  daysApart(date day1, date day2); 
	void input();

private:





};

int days :: daysApart(date day1, date day2)
{
	if (day1 == day2)
	{
		return 0;
	}
	else if (day1 < day2)
	{
		//bob
		int count = 0;
		while (day1!=day2)
		{
			day1++;
			//cout << day1 << endl;
			
			cout << day1 << endl;
			count++;
		}
		cout << "the count is " << count << endl;
	}
	else
	{
		int count = 0;
		while (day2 != day1)
		{
			day2++;
			count++;
			cout << day2 << endl;

		}

		cout << "the count is " << count << endl;
	}
}

void days ::input()
{
	date day1;
	date day2;
	int month1;
	int month2;
	int days1;
	int days2;
	int year1;
	int year2;
	bool run = true;
	string answer;

	while (run)
	{
		cout << "whats the first date in order of month day year";
		cin >> month1;
		cin >> days1;
		cin >> year1;
		day1.setDate(month1, days1, year1);
		cout << "whats the second date in order of month day year";
		cin >> month2;
		cin >> days2;
		cin >> year2;
		day2.setDate(month2, days2, year2);
		daysApart(day1, day2);
		cout << "do you want to stop running" << endl;
		cin >> answer;
		if (answer.compare((string) "y") == 0 || answer.compare((string) "Yes") == 0 || answer.compare((string) "yes") == 0 || answer.compare((string) "YES") == 0)
		{
			run = false;
		}
		else
		{
			run = true;
		}
	}
}


