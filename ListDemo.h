#include <iostream>
//#include <iostream>
#include<exception>
#include <string>


struct listNode
{
	int  data;
	listNode  *next;
};

typedef listNode* nodePtr;

void createList(nodePtr &);
void printList(nodePtr);
void insert(nodePtr &, int value);

main()
{
	nodePtr first;

	createList(first);
	printList(first);
	return 0;
}

void createList(nodePtr &root)
{
	root = NULL;
	for (int k = 1; k <= 5; k++)
		insert(root, k);
}

//void insert(nodePtr &root, int value)
//{
//	nodePtr newNode;
//
//	newNode = new listNode;
//	newNode->data = value;
//	newNode->next = root;
//	root = newNode;
//}

void insert(nodePtr &temp, int value)
//  Takes in value, packages it in a new node, inserts the new node at the end of the list.
{
	listNode(*first);
	listNode(*last);
	if (first == NULL && last == NULL)
	{
		listNode node;
		node.data = 0;
		node.next = temp;
		*first = node;
		*last = node;
	}
	else
	{
		listNode node;
		node.data = value;
		node.next = temp;
		
	}
	/*if an empty list then
		set both first and last pointers to the newly constructed node
	else
		construct a new node at the end of the list*/

}

void printList(nodePtr temp)
{
	while (temp != NULL)
	{
		cout << temp->data << "   ";
		temp = temp->next;
	}
	cout << endl;
}
