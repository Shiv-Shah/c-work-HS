#pragma once
#include <iostream>
#include <string>

using namespace std;


class date {
public:
	date()
	{
		myMonth = 1;
		myDay = 1;
		myYear = 1;
	}// default constructor, date is set to valid values of your choice
	date(int month, int day, int year)
	{
		myMonth = month;
		myDay = day;
		myYear = year;
	}// constructor with initial values of month, day, and year
	date(const date &temp)
	{
		myMonth = temp.myMonth;
		myDay = temp.myDay;
		myYear = temp.myYear;

	}// copy constructor, self is constructed as a copy of temp
	void setDate(int month, int day, int year);  // set values for date
	void getDate();  // get date from keyboard
	void print() const;   // public print function

private:
	int myMonth, myDay, myYear;
	int daysInMonth(int month, int year);	// suggested private member function
};




void date::setDate(int month, int day, int year)
{
	bool check_month = true;
	bool check_year = true;
	bool check_day = true;
	while (check_month)
	{
		//cout << "what month are you in 1= january 2 = febuary 3 = march etc" << endl;
		if (month > 0 && month < 13)
		{
			myMonth = month;
			check_month = false;
		}
		else
		{
			cout << "your month is not valid choose a month" << endl;;
			cin >> month;
		}
	}


	while (check_year)
	{
		if (year >0 && year < 100)
		{


			cout << "what year are you in 1-19 = 2001-2019 20-99 = 1920-1999 0 or 00 = 2000 " << endl;;
			if (year >= 20 && year <= 99)
			{
				myYear = year + 1900;
				check_year = false;
			}
			else if (year == 0 || year == 00)
			{
				myYear = 2000;
				check_year = false;
			}
			else
			{
				myYear = 2000 + year;
				check_year = false;
			}
		}
		else
		{
			cout << "your year is not valid choose a valid year" << endl;
			cin >> year;
		}
	}



	if (myMonth == 1 || myMonth == 3 || myMonth == 5 || myMonth == 7 || myMonth == 8 || myMonth == 10 || myMonth == 12)
	{
		while (check_day)
		{


			if (day < 32 && day > 0)
			{
				myDay = day;
				check_day = false;
			}
			else
			{
				cout << "your date is not valid choose a valid date" << endl;
				cin >> day;
			}
		}
	}
	else if (myMonth == 4 || myMonth == 6 || myMonth == 9 || myMonth == 11)
	{

		while (check_day)
		{


			if (day < 31 && day > 0)
			{
				myDay = day;
				check_day = false;
			}
			else
			{
				cout << "your date is not valid choose a valid date" << endl;
				cin >> day;
			}
		}
	}

	else
	{
		if (year % 4 == 0 && year % 400 != 0)
		{

			while (check_day)
			{

				cout << "there are 29 days in Febuary hence giving mone more day so choose a day." << endl;
				if (day < 30 && day > 0)
				{
					myDay = day;
					check_day = false;
				}

			}
		}
		else
		{

			while (check_day)
			{

				cout << "there are 28 days in Febuary hence giving mone more day so choose a day." << endl;
				if (day < 29 && day > 0)
				{
					myDay = day;
					check_day = false;
				}
				else
				{
					cout << "your date is not valid choose a valid date" << endl;
					cin >> day;
				}
			}

		}
	}
}


int date::daysInMonth(int month, int year)
{
	bool cont = true;
	while (cont)
	{
		if (myMonth < 13 && myMonth > 0)
		{
			if (myMonth == 1 || myMonth == 3 || myMonth == 5 || myMonth == 7 || myMonth == 8 || myMonth == 10 || myMonth == 12)
			{
				cout << "There are 31 days in" << myMonth;
				cont = false;
				return 31;
			}

			else if (myMonth == 4 || myMonth == 6 || myMonth == 9 || myMonth == 11)
			{
				cout << "There are 30 days in" << myMonth;
				cont = false;
				return 30;
			}
			else
			{
				if (year % 4 == 0 && year % 400 != 0)
				{
					cout << "there are 29 days in" << myMonth << endl;
					return 29;
				}
				else
				{
					cout << "there are 28 days in" << myMonth << endl;
					return 28;
				}
			}
		}
		else
		{
			cout << "your moth is not valid choose a valid month" << endl;
			cin >> month;
		}
	}
}
void date::getDate()
{
	int month;
	int day;
	int year;
	cout << "Choose a month using numbers ie january = 1" << endl;
	cin >> month;
	cout << "Choose a day using" << endl;
	cin >> day;
	cout << "Choose a year using " << endl;
	cin >> year;

	setDate(month, day, year);


}


void date::print() const
{
	cout << myMonth << "/" << myDay << "/" << myYear << endl;
}

