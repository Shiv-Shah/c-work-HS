#pragma once
#include <iostream>
//#include "dice.h"
#include <vector>
#include <fstream>
#include <math.h>
#include <ctgmath>
#include "Header.h"
//#include "C:\Users\041123\Documents\Visual Studio 2015\Projects\18\18\life100.txt"

using namespace std;

class sorts1
{
public:
	sorts1()
	{
		mySteps = 0;
	}
	void bubbleSort(vector <Item> &list);
	void selectionSort(vector <Item> &list);
	void insertionSort(vector <Item> &list);
	void mergeSort(vector <Item> &a, int first, int last);
	void merge(vector <Item> &list, int first, int mid, int last);
	void quickSort(vector <Item> &a, int first, int last);
	void screenoutput(vector<Item> num);
	//void screenOutput(vector<int> num);
	long getStepCount();
	void setStepCount(long step);
	//void fillArrayWithInts(vector <int> &num);

private:
	long mySteps;





};

void sorts1::quickSort(vector <Item> &a, int first, int last)
{
	int g = first, h = last;
	int midIndex = (first + last) / 2;
	int dividingValue = a.at(midIndex).id;
	do {
		while (a.at(g).id-(dividingValue) < 0) g++;
		while (a.at(h).id-(dividingValue) > 0) h--;
		if (g <= h) {
			//int temp = list.get(g);
			swap(a.at(g), a.at(h));
			//list.set(g, list.get(h));
			//list.set(h, temp);
			mySteps++;
			g++;
			h--;
		}
	} while (g < h);
	if (h > first) quickSort(a, first, h);
	if (g < last) quickSort(a, g, last);
}

void sorts1::screenoutput(vector<Item> num)
{
	
	for (int loop = 0; loop < num.size(); loop++)
	{
		if (loop % 12 == 0)
		{
			cout << endl;
		}
		cout << num[loop].id << "       " << num[loop].inventory << endl;
	}
	cout << endl;
}


