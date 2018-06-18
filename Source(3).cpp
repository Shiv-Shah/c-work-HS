#include <iostream>

#include<exception>
#include <string>
using namespace std;


//struct listNode
//{
//	int  data;
//	listNode  *next;
//};
//
//typedef listNode* listType;
//
//void createList(listType &);
//void printList(listType);
//void insert(listType &, int value);
//listNode(*first);
//listNode(*last);
//
//int main()
//{
//	listType first;
//
//	createList(first);
//	printList(first);
//	return 0;
//}
//
//void createList(listType &root)
//{
//	root = NULL;
//	for (int k = 1; k <= 20; k++)
//		insert(root, k);
//}
//
//
//void insert(listType &temp, int value)
////  Takes in value, packages it in a new node, inserts the new node at the end of the list.
//{
//
//	if (first == NULL && last == NULL)
//	{
//		listNode node;
//		node.data = 1;
//		node.next = temp;
//		*first = node;
//		*last = node;
//	}
//	else
//	{
//		listNode node;
//		node.data = value;
//		node.next = temp;
//
//	}
//	/*if an empty list then
//	set both first and last pointers to the newly constructed node
//	else
//	construct a new node at the end of the list*/
//
//}
//
//void printList(listType temp)
//{
//	while (temp != NULL)
//	{
//		cout << temp->data << "   ";
//		temp = temp->next;
//	}
//	cout << endl;
//}

//#include <iostream.h>

struct listNode
{
	int  data;
	listNode  *next;

	listNode(int, listNode *);
};

listNode::listNode(int tempData, listNode *tempNext)
	: data(tempData), next(tempNext)
{
	// all values initialized in initializer list
}

typedef  listNode*  listPtr;

struct  listType
{
	listPtr  first;
	listPtr  last;
};


void createList(listType &);
void printList(listType);
void countNodes(listType temp);
int counter;

int main()
{
	listType L;

	createList(L);
	printList(L);
	countNodes(L);
	system("pause");
	return 0;
}

void createList(listType &root)
{
	

	root.first = NULL;
	root.last = NULL;
	
	
		for (int k = 20; k > 0; k--)
		{
			root.first = new listNode(k, root.first);
			counter++;
			if (k == 20)
			{
				root.last = root.first;
			}
		}
		
}


void printList(listType temp)
{
	listPtr check = temp.first;
	while (check >= temp.last)
	{
		cout << check->data << "   ";
		check = check->next;
	}
	cout << endl;
	

	
}


void countNodes(listType temp)
{
	int count = 0;
	listPtr check = temp.first;
	do
	{
		check->data;
		check = check->next;
		count++;
	} while (check >=temp.last);
	cout << count << endl;

}








