#pragma once
#include <iostream>
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