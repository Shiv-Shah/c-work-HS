
#include <iostream>
#include "Header.h"
#include <string>

using namespace std;

int main()
{
	int temp2;
	RPN temp;
	int power = 0;
	int response = 0;
	do
	{
		response = temp.calculate();
		temp.toString(response);
		cout << "if you want to continue press any letter or number to stop running the driver write -1: " << endl;
		cin >> temp2;
	} while (temp2 != -1);
}