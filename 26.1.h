#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "item.h"
#include "sorts.h"

using namespace std;


class Search
{
public:

	void testSearch(const storeType &store);
	void sort(vector <Item> &foo);

private:

	int bsearch(const storeType &store, int idToSearch);
	int bsearch(const storeType &store, int idToSearch, int first, int last);
	void quickSort(vector <Item> &a, int first, int last);





};



void Search::testSearch(const storeType &store)
{
	int idToFind, invReturn, index;

	cout << "Testing search algorithm" << endl << endl;
	cout << "Enter Id value to search for (-1 to quit) ---> ";
	cin >> idToFind;
	while (idToFind >= 0)
	{
		//index = bsearch(store, idToFind);
			index = bsearch (store, idToFind, 0, store.list.size()-1); //   recursive version call
		cout << "Id # " << idToFind;
		if (-1 == index)
			cout << "     No such part in stock" << endl;
		else
			cout << "     Inventory = " << store.list[index].inventory << endl;
		cout << endl << "Enter Id value to search for (-1 to quit) ---> ";
		cin >> idToFind;
	}
}


//	/*	precondition:  store.list is sorted by the id field.  store.number stores how many items are in the array.
//	data is stored in the array list from positions 0..store.number-1.

//	postcondition:  if idToSearch exists in the array, the function returns the index position of the item, otherwise it returns -1.  */
int Search::bsearch(const storeType &store, int idToSearch)
{
	//bool finished = false;
	int i = 0;
	int low = 0;
	int high = store.list.size();
	while (low <= high)
	{
		i = (low+high) / 2;

		if (store.list[i].id ==idToSearch)
		{
			//cout << store.list[i].id << "          " << store.list[i].inventory << endl;
			return i;
		}
		else if (store.list[i].id > idToSearch)
		{
			high = i - 1;
		}
		else
		{
			low = i + 1;
		}
	}

	return -1;
}

int Search::bsearch(const storeType &store, int idToSearch, int first, int last)
{
	int low = first;
	int high = last;

	//vector <Item> copy;
	int mid = 0;
	//Item guess = store.list[idToSearch];

	if (low <= high)
	{
		mid = (first + last) / 2;
		if (store.list[mid].id == idToSearch)
		{
			return mid;
		}
		else if (store.list[mid].id > idToSearch)
		{
			return bsearch(store, idToSearch, first, mid - 1);
		}
		else
		{
			return bsearch(store, idToSearch, mid + 1, last);
		}
	}

	return -1;
}



//	//	recursive version, searches range from first to last of the array

void Search::quickSort(vector <Item> &a, int first, int last)
{
	int g = first, h = last;
	int midIndex = (first + last) / 2;
	int dividingValue = a.at(midIndex).id;
	do {
		while (a.at(g).id < (dividingValue)) g++;
		while (a.at(h).id > (dividingValue)) h--;
		if (g <= h) {
			//int temp = list.get(g);
			swap(a.at(g), a.at(h));
			//list.set(g, list.get(h));
			//list.set(h, temp);
			//mySteps++;
			g++;
			h--;
		}
	} while (g < h);
	if (h > first) quickSort(a, first, h);
	if (g < last) quickSort(a, g, last);
}


void Search::sort(vector <Item> &matt)
{
	//vector <Item> ;
	int num = 0;
	int id = 0;
	int inv = 0;
	//int blade;
	ifstream inFile;
	inFile.open("C:\\Users\\041123\\Documents\\Visual Studio 2015\\Projects\\25\\25\\FILE20.txt", ios::in);

	storeType temp;
	int mysteps = 0;
	Item shiv;
	sorts pete;
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
	quickSort(matt, 0, matt.size() - 1);
	for (int loop = 0; loop < matt.size(); loop++)
	{
		if (loop % 12 == 0)
		{
			cout << endl;
		}
		cout << matt[loop].id << "      " << matt[loop].inventory << endl;
	}
	//cout << endl;
//pete.screenoutput(matt);
//system("pause");
//return 0;
}








