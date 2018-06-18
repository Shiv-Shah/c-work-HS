//  ordShell.cpp
//  A program shell for the ordered linked list lab, Lesson 33

#include <iostream>
#include <iomanip>
#include <fstream>
//#include <bool>
//#include <apstring.h>
#include <stdlib.h>
#include <string>

using namespace std;

const string SOURCE = ("C:\\Users\\041123\\Documents\\Visual Studio 2015\\Projects\\33\\33\\FILE20.txt");

struct listNode
{
	int  id, inv;
	listNode  *next;

	listNode(int tempId, int tempInv, listNode *nxt);
};

listNode::listNode(int tempId, int tempInv, listNode *nxt)
	: id(tempId), inv(tempInv), next(nxt)
{
	// all values initialized using initializer list
}

typedef listNode* nodePtr;

struct listType
{
	nodePtr first;
	nodePtr last;
};

void insertInOfOrder(listType &, int, int);
nodePtr search(listType, int);
bool removeNode(listType &, int);
void testSearch(listType);
void testDelete(listType &);
void clearList(listType &);
void printList(listType);
int countNodes(listType);
void readData(listType &);
void printBackward(nodePtr temp);
void mainMenu(listType &);


int main()
{
	listType list;

	list.first = list.last = NULL;
	mainMenu(list);
	return 0;
}


void insertInOrder(listType &L, int id, int inv)
{
	nodePtr temp = new listNode(id, inv, NULL);
	if (NULL == L.first)
		L.first = L.last = new listNode(id, inv, L.first);
	else if (L.first->id >= id)
	{
		L.first = new listNode(id, inv, L.first);
	}
	else if (L.last->id <= id)
	{
		L.last->next = temp;
		L.last = temp;
	}
	else
	{
		nodePtr before = L.first;
		while ((before->next)->id < id)
		{
			before = before->next;
		}
		temp->next = before->next;
		before->next = temp;

	}
}


nodePtr search(listType temp, int idToFind)
{

	nodePtr before = temp.first;

	for (before; before->id <= temp.last->id; before = before->next)
	{
		if (before->next != NULL)
		{
			if (before->id == idToFind)
			{
				return before;
			}
		}
		else
		{
			return NULL;
		}

	}

	return NULL;
}


void testSearch(listType temp)
{
	int idToFind;
	nodePtr location;

	cout << "Testing search algorithm" << endl << endl;
	cout << "Enter Id value to search for (-1 to quit) ---> ";
	cin >> idToFind;
	while (idToFind >= 0)
	{
		location = search(temp, idToFind);
		cout << "Id # " << idToFind;
		if (NULL == location)
			cout << "     No such part in stock" << endl;
		else
			cout << "     Inventory = " << location->inv << endl;
		cout << endl << "Enter Id value to search for (-1 to quit) ---> ";
		cin >> idToFind;
	}
}

bool removeNode(listType &temp, int idToDelete)
{
	nodePtr finder = temp.first;
	nodePtr before = temp.first;
	nodePtr after = temp.first;

	for (finder; finder->id <= temp.last->id; finder = finder->next)
	{
		if (finder->id == idToDelete && finder->id == temp.first->id)
		{

			temp.first = finder->next;
			return finder;
		}
		else if (finder->id == idToDelete && finder->id == temp.last->id)
		{
			temp.last = before;
			temp.last->next = NULL;
			return finder;
		}
		else  if (finder->id == idToDelete)
		{
			before->next = finder->next;
			return finder;
		}
		if (before != finder)
		{
			before = before->next;
		}

		if (finder->next != NULL)
		{
			after = finder->next;
		}
		else
		{
			return NULL;
		}


		//cout << finder->id << endl;
	}
	return NULL;
}

void testDelete(listType &temp)
{
	int idToDelete;
	bool success;

	cout << "Testing delete algorithm" << endl << endl;
	cout << "Enter Id value to delete (-1 to quit) ---> ";
	cin >> idToDelete;
	while (idToDelete >= 0)
	{
		success = removeNode(temp, idToDelete);
		cout << "Id # " << idToDelete;
		if (!success)
			cout << "     No such part in stock" << endl;
		else
			cout << "     Id #" << idToDelete << " was deleted" << endl;
		cout << endl << "Enter Id value to delete (-1 to quit) ---> ";
		cin >> idToDelete;
	}
}

void clearList(listType &local)
{
	cout << "Clear list" << endl;
	local.first = NULL;
	local.last = NULL;
	
}


void printList(listType local)
{
	nodePtr temp = local.first;
	int line = 1;

	cout << setiosflags(ios::right);
	cout << setw(15) << "Id" << setw(10) << "Inv" << endl << endl;
	while (temp != NULL)
	{
		cout << setw(5) << setw(10) << temp->id << setw(10) << temp->inv << endl;
		if (line % 10 == 0) cout << endl;
		temp = temp->next;
		line++;
	}
}


int countNodes(listType local)
{
	int count = 0;
	//listPtr check = temp.first;
	nodePtr check = local.first;
	do
	{
		check->id;
		check = check->next;
		count++;
	} while (check >= local.last);
	cout << count << endl;
	return count;
}

void readData(listType &temp)
{
	ifstream inFile;
	int howMany, k, id, inv;

	inFile.open(SOURCE.c_str());
	if (inFile.fail())
	{
		cerr << "Could not open " << SOURCE << endl;
		abort();
	}
	inFile >> howMany;
	for (k = 0; k < howMany; k++)
	{
		inFile >> id >> inv;
		insertInOrder(temp, id, inv);
	}
}
void printBackward(nodePtr temp)
{
	//int line = 1;
	if (temp == NULL)
	{
		return;
	}
	printBackward(temp->next);
	//cout << "Printing backward" <<  endl;
	cout << setw(5)  << setw(10) << temp->id << setw(10) << temp->inv << endl;
	//line++;
}

void mainMenu(listType &temp)
{
	char choice, print;

	do
	{
		cout << "Linked List algorithm menu" << endl << endl;
		cout << "(1) Read file20.txt from disk" << endl;
		cout << "(2) Print ordered list" << endl;
		cout << "(3) Search list" << endl;
		cout << "(4) Delete from list" << endl;
		cout << "(5) Clear entire list" << endl;
		cout << "(6) Count nodes in list" << endl;
		cout << "(7) Print list backwards" << endl;
		cout << "(8) Quit" << endl << endl;
		cout << "Choice ---> ";
		cin >> choice;
		cin.get();	// to dump return key
		cout << endl;
		if ('1' <= choice && choice <= '7')
		{
			switch (choice)
			{
			case '1': readData(temp); break;
			case '2': printList(temp); break;
			case '3': testSearch(temp); break;
			case '4': testDelete(temp); break;
			case '5': clearList(temp); break;
			case '6':
				cout << "Number of nodes = " << countNodes(temp) << endl << endl;
				break;
			case '7':
				cout << setw(10) << "Id" << setw(10) << "Inv" << endl << endl;
				printBackward(temp.first); break;
			}
		}
	} while (choice != '8');
}
