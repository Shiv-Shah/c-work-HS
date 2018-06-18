#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


struct Item
{
	int id;
	int inventory;

};

struct storeType
{
	vector<Item> list;
	int number;

};

