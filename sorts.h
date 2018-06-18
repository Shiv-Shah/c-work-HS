#pragma once
#include <iostream>
//#include "dice.h"
#include <vector>
#include <fstream>
#include <math.h>
#include <ctgmath>
//#include "C:\Users\041123\Documents\Visual Studio 2015\Projects\18\18\life100.txt"

using namespace std;

class sorts
{
public:
		sorts()
		{
			mySteps = 0;
		}
		void bubbleSort(vector <int> &list);
		void selectionSort(vector <int> &list);
		void insertionSort(vector <int> &list);
		void mergeSort(vector <int> &a, int first, int last);
		void merge(vector <int> &list, int first, int mid, int last);
		void quickSort(vector <int> &a, int first, int last);

		//void screenOutput(vector<int> num);
		long getStepCount();
		void setStepCount(long step);
		//void fillArrayWithInts(vector <int> &num);

private:
	long mySteps;



	

};

void sorts::bubbleSort(vector <int> &list)
{
	for (int h = 0; h < list.size(); h++) {
		for (int i = 0; i < list.size() - h - 1; i++) {
			if (list[i] > (list[i+1]) )
			{
				int temp = list[i];
				swap(list[i], list[i+1]);
				int num = i + 1;
				swap( list[num] , temp);
				
				mySteps++;
			}
			// do et you fool
		}
	}
}


void sorts::selectionSort(vector <int> &list)
{
	int temp;
	int min;

	for (int outer = 0; outer < list.size() - 1; outer++)
	{
		min = outer;
		for (int inner = outer + 1; inner < list.size(); inner++)
		{
			if (list[inner] < (list[min])  )
				min = inner;  // a new smallest item is found

		}
		//swap list[outer] & list[min]
		temp = list[outer];
		swap(list[outer], list[min]);
		swap (list [min], temp);
		mySteps++;
	}
}

void sorts :: insertionSort(vector <int> &list)
{
	for (int h = 0; h<list.size(); h++) {
		int pos = h;
		int key = list[pos];
		while (pos>0 &&  list[pos-1]>key  ) 
		{
			swap(list[pos], list[pos - 1]);
			pos--;
		}
		swap(pos, key);
		mySteps++;
	}

	
}

//void sorts::screenOutput(vector<int> num)
//{
//	
//	for (int loop = 0; loop < num.size(); loop++)
//	{
//		if (loop % 12 == 0)
//		{
//			cout << endl;
//		}
//		cout << (num[loop] + "  ");
//	}
//	cout << endl;
//}


//void sorts ::fillArrayWithInts(vector<int> &num)
// {
	
// }

long sorts::getStepCount()
{
	return mySteps;
}

void sorts::setStepCount(long step )
{
	mySteps = step;
}


void sorts:: mergeSort(vector <int> &a, int first, int last)
{
	if (last - first == 0)
	{
		//do nothing
	}
	else if (last - first == 1)
	{
		if (a[first]>(a[last]))
		{
		//	int temp = a[first];
			swap(a[first], a[last]);
		//	a.at(first) = a.at(last);
			//a.at(last) = temp;
		//swap(a[last], temp);
			//set(first, a[last]);
			//set(last, temp);
	//		cout << "145" << endl;

		}
	}
	else
	{    // recursion, divide list into two halves
		int mid = (first + last) / 2;
	//	cout << "152" << endl;
		mergeSort(a, first, mid);
	//	cout << "154" << endl;
		mergeSort(a, mid + 1, last);
	//	cout << "156" << endl;
		merge(a, first, mid, last);
	//	cout << "158" << endl;
		//mySteps++;
	}
}


void sorts::merge(vector <int> &list, int first, int mid, int last)
{
	vector <int> copy;
	for (int temp : list)
	{
		copy.push_back(temp);
	}
	int index = first;
	int index2 = mid + 1;
	int num;

	for (int i = first; i <= last; i++)
	{
		//num = i;

		if (index>mid)
		{
			//list.at(i) = copy.at(index);
			swap (list.at(i),copy.at(index2));
			//	list.erase(copy.begin() + i);
			//list.emplace(list.begin() + i, list[i]);
			//list.at(i) = list.at(index2);
			

			index2++;
			//cout << "189" << endl;
		}
		else if (index2>last)
		{
			//list.set(i, copy.at(index));
			//list.at(i) = copy.at(index);
			//list.erase(copy.begin() + i);
			//copy.at(index2) = num;
			swap(list.at(i), copy.at(index));
			//list.emplace(list.begin() + i, list[i]);
			//list.at(i) = list.at(index);

			index++;
			//cout << "202" << endl;
		}
		else if (copy.at(index) < (copy.at(index2)))

		{
			//list.set(i, copy.at(index));
			//list.at(i) = copy.at(index);
			swap(list.at(i), copy.at(index));
			//copy.at(index2) = num;
			// list.erase(copy.begin() + i);
			//list.emplace(list.begin() + i, list[i]);
			//list.at(i) = list.at(index);
			index++;
			//cout << "215" << endl;
		}
		else
		{
			//list.set(i, copy.at(index2));
			//list.at(i) = copy.at(index2);
			//copy.at(index2) = num;
			swap(list.at(i), copy.at(index2));
			//	list.erase(copy.begin() + i);
			//list.emplace(list.begin() + i, list[i]);
			//list.at(i) = list.at(index2);
			index2++;
			//cout << "227" << endl;
		}
	}
}


 void sorts:: quickSort(vector <int> &a, int first, int last)
{
	int g = first, h = last;
	int midIndex = (first + last) / 2;
	int dividingValue = a.at(midIndex);
	do {
		while (a.at(g)<(dividingValue) ) g++;
		while (a.at(h)>(dividingValue) ) h--;
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
