#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include <string>

using namespace std;
class RPN
{
public:
	int calculate();
	string toString(int &answer);


private:
	stack<int> stack;
	queue<string> queues;
	queue <string> temp;
	void calculating();


};

int RPN::calculate()
{
	string typed = "";
	do
	{
		
		cout << "Enter digits or an operator for the expression to be processed (press Q to exit)" << endl;
		cin >> typed;
		if (typed.compare("") == 0)
		{
			cout << "You didn't type anything" << endl;
		}
		else if (typed.compare("*") == 0 || typed.compare("+") == 0|| typed.compare("-") == 0|| typed.compare("/") == 0)
		{
			temp.push(typed);
			if (typed.compare("*") == 0)
			{
				queues.push("*");
			}
			else if (typed.compare("+") == 0)
			{
				queues.push("+");
			}
			else if (typed.compare("-") == 0)
			{
				queues.push("-");
			}
			else if (typed.compare("/") == 0)
			{
				queues.push("/");
			}
			calculating();
		}
		else if (typed.compare("0") == 0 || typed.compare("0") == 1 || typed.compare("0") == 2|| typed.compare("0") == 3|| typed.compare("0") == 4 || typed.compare("0") == 5 || typed.compare("0") == 6 || typed.compare("0") == 7 || typed.compare("0") == 8 || typed.compare("0") == 9)
		{
			if (typed.compare("0") == 0)
			{
				stack.push(0);
			}
			else if (typed.compare("1") == 0)
			{
				stack.push(1);
			}
			else if (typed.compare("2") == 0)
			{
				stack.push(2);
			}
			else if (typed.compare("3") == 0)
			{
				stack.push(3);
			}
			else if (typed.compare("4") == 0)
			{
				stack.push(4);
			}
			else if (typed.compare("5") == 0)
			{
				stack.push(5);
			}
			else	if (typed.compare("6") == 0)
			{
				stack.push(6);
			}
			else	if (typed.compare("7") == 0)
			{
				stack.push(7);
			}
			else	if (typed.compare("8") == 0)
			{
				stack.push(8);
			}
			else	if (typed.compare("9") == 0)
			{
				stack.push(9);
			}
			else if( typed.compare (""))
			{
				cout << " You either are putting a wierd value or a letter Be Warned if you try to add letters it will crash like an actual calculator" << endl;
			}
		}
	}
	while (!typed.compare("Q")== 0 && !typed.compare("q") == 0);
	cout << endl;
	while (queues.empty() == false)
	{
		calculating();
	}
	try
	{
		return stack.top();
	}
	catch(logic_error )
	{
		cout << "you didn't do anything or the calculator is incorrect" << endl;
		return 0;
	}
}


void RPN::calculating()
{
	int temp;
	int temp2;
	string str;
	temp = stack.top();
		stack.pop();
	temp2 = stack.top();
	stack.pop();
	str = queues.front();
	queues.pop();
	if (str.compare("-") == 0)
	{
		temp = temp2 - temp;
	}
	else if (str.compare("+") == 0)
	{
		temp = temp2 + temp;
	}
	else if (str.compare("*") == 0)
	{
		temp = temp2*temp;
	}
	else
	{
		temp = temp2 / temp;
	}
	stack.push(temp);
}

string RPN::toString(int &answer)
{
	while (!temp.empty())
	{
		cout << temp.front()  <<  " ";
		temp.pop();
	}
//	System.out.println("= " + answer + "\n");
	cout << "= " << answer << "\n" << endl;
	return "";
}