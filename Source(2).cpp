#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Header.h"
//#include "sorts.h"
#include "Header1.h"

using namespace std;

int main()
{
	vector <Item> matt;
	int num = 0;
	int id = 0;
	int inv = 0;
	//int blade;
	ifstream inFile;
	inFile.open("C:\\Users\\041123\\Documents\\Visual Studio 2015\\Projects\\25\\25\\FILE20.txt",ios :: in);
	
	 storeType temp;
	 int mysteps = 0;
	 Item shiv;
	 sorts1 pete;
	 int numEnteries;

	 inFile >> num;
	 numEnteries = num;
	 
	 
	// matt[]
	 

	 for (int i = 0; i < numEnteries; i++)
	{
		inFile >> id;
		//temp.number = id;
		inFile >> inv;
		//blade = inv;
		shiv.id = id;
		shiv.inventory = inv;
		temp.list.push_back(shiv);
		matt.push_back(shiv);

		
		//matt[id] = blade;

	}
	pete.quickSort(matt,0 ,matt.size()-1 );
	pete.screenoutput(matt);
	system("pause");
	return 0;


 
	



}




