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

struct listNode
{
	int  data;
	listNode  *next;

	listNode(int, listNode *);	// struct constructor
};

listNode::listNode(int tempData, listNode * tempNext)
{
	data = tempData;
	next = tempNext;
}

typedef  listNode*  listPtr;

struct  listType
{
	listPtr  first;
	listPtr  last;
};


