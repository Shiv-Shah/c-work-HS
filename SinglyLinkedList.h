#pragma once
#include"listNode.h"
#include <iostream>
#include<exception>
using namespace std;


class singlylinkedlist
{
public:
	singlylinkedlist()
	{
		(*first).data = 0;
		(*first).next = NULL;
		(*last).data = 0;
		(*last).next = NULL;

		

	}
	int getfirst();
	int getlast();
	void addfirst(int value);
	void addlast(int value);
	int size();
	void printlist();
	listNode find(int value);
	void insert(int value);
	string tostring();
	void printbackwards();
	void printbackwards(listNode node);
	bool remove(int value);
	void clear();

	listNode find(int value);
private:
	listNode *first;
	listNode *last;
	int numbernodes;

};



//private listNode first;  // first element  
//private int numbernodes;
//private listNode first;
/**
*  constructor for the singlylinkedlist int
*  generates an empty list.
*/
//public singlylinkedlist() {
//	first = NULL;
//	numbernodes = 0;
//	last = NULL;
//}

/**
*  returns the first element in this list.
*
* @return  the first element in the linked list.
*/
 int singlylinkedlist :: getfirst() {
	 if (first == NULL) {
		 throw new bad_exception;
	 }
	 else
		 return (*first).data;
}

 int singlylinkedlist::getlast()
{
	if (last == NULL)
	{
		throw new bad_exception;
	}
	else
	{
		return (*last).data;
	}
}

/**
*  inserts the given element at the beginning of this list.
*
* @param  value  the element to be inserted at the beginning of this list.
*/
 void singlylinkedlist:: addfirst(int value) {
	// note the order that things happen:
	// head is parameter, then assigned
	first = new listNode(value, first);
	if (last == NULL) {
		last = first;
	}
}

 void singlylinkedlist::addlast(int value)
// takes in value, creates a new node, adds the new node
// at the end of the list.
{
	//if an empty list then
	//set both first and last to reference the newly constructed node
	// else
	//construct a new node at the end of the list
	if (first == NULL)
	{
		last = new listNode(value, last);
		first = last;

	}
	else
	{
		//             listNode matt = new listNode(
		listNode *matt;
		(*matt).data = value;
		(*matt).next = NULL;

		(*last).next = (matt);
		last = (matt);

	}
}

 int singlylinkedlist:: size()
{
	listNode (*temp) = first;
	int temp2 = 0;
	while (temp != NULL)
	{
		temp2++;
		//(*temp) = (temp).next;
	}
	numbernodes = temp2;
	return numbernodes;
}

/**
*  print the contents of the entire linked list
*/
 void singlylinkedlist::printlist() {
	listNode (*temp)  = first;// start from the first node
	while (temp != NULL)
	{
		//system.out.println(temp.getvalue() + " ");
		cout << &temp << " " << endl;
		//(*temp) = (*temp).next;// go to next node
	}
}

/**
*  returns a string representation of this list. the string
*  representation consists of the list's elements in order,
*  enclosed in square brackets ("[]"). adjacent elements are
*  separated by the characters ", " (comma and space).
*
* @return    string representation of this list
*/
 string singlylinkedlist::tostring() {
	string s = "[";

	listNode (*temp) = first;  // start from the first node
	while (temp != NULL) {
		s += &temp // append the data
		temp = temp.getnext();      // go to next node
		if (temp != NULL)
			s += ", ";
	}
	s += "]";
	return s;
}

 void singlylinkedlist::insert(int value)
{
	if (value != NULL)
	{
		if ((first) == NULL || value == (int)first)
		{
			addfirst(value);
		}
		else if (value ==(int)last)
		{
			addlast(value);
		}
		else
		{
			listNode temp = (*first);
			listNode temp2 = temp;
			//temp = (temp).next;

			while ((&temp) != NULL)
			{
				if (((int)temp == value >= 0)
				{
					listNode newnode = new listNode(value, temp);
					temp2.setnext(newnode);
					return;
				}
				else
				{
					temp2 = temp;
					temp = temp.getnext();

				}
			}
		}

	}
	else
	{
		throw new nosuchelementexception();
	}
}

public listNode find(int value)
{
	if (value == NULL)
	{
		throw new nosuchelementexception();
	}
	listNode temp = first;
	while (temp != NULL)
	{
		if (((int)temp.getvalue()).equals(value))
		{
			return temp;
		}
		else
		{
			temp = temp.getnext();

			if (temp == NULL)
			{
				return NULL;
			}
		}
	}
	return NULL;

}

public void printbackwards()
{
	printbackward(first);

}

public void printbackward(listNode node)
{
	if (node == NULL)
	{
		return;
	}
	printbackward(node.getnext());
	system.out.println((int)node.getvalue() + " ");
}

public boolean remove(int value)
{
	listNode temp = first;
	listNode temp2 = temp;
	if (value != NULL)
	{
		int next;
		int next2;
		if (temp == NULL)
		{
			return false;
		}
		else
		{
			next = (int)temp.getvalue();
			temp.getnext();
			next2 = (int)temp2.getvalue();
		}
		while (temp != NULL)
		{
			if (next.equals(value))
			{
				if (next.equals((int)first.getvalue()))
				{
					first = first.getnext();
				}
				else if (next.equals((int)last.getvalue()))
				{
					last = temp2;
					temp2.setnext(NULL);
				}

				else
				{
					temp2.setnext(temp.getnext());
				}
				return true;
			}
			else
			{
				temp2 = temp;
				temp = temp.getnext();
				if (temp == NULL)
				{
					return false;
				}
				else
				{
					next = (int)temp.getvalue();
					next2 = (int)temp2.getvalue();
				}
			}
		}
	}
	if (size() == 1 && ((int)temp.getvalue()).equals(value) && temp != NULL)
	{
		clear();
		return true;
	}
	return false;
}

public void clear()
{
	         listNode temp = first;
	         while(temp!= NULL )
	         {
	             remove((int)temp.getvalue());
	             temp = temp.getnext();
	 
	         }
	         remove((int)last.getvalue());
	first = NULL;
	last = NULL;
}
