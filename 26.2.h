#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "item.h"
#include "sorts.h"
#include "Incensitive_Case.h"

using namespace std;
class countwords
{
public:
	countwords(string Filename)
	{

		inFile.open(Filename, ios::in);
		string temp;
		bool foo = false;
		while (inFile >> temp)
		{
			for (int i = 0; i < temp.length(); i++)
			{
				temp[i] = tolower(temp[i]);
				
				if (temp[i] == 71 || temp[i] == 77)
				{
					temp.erase(temp.begin() + i);
				}
			}


			while (!foo)
			{
				if (temp != "")
				{
					if (temp.back() == ',' || temp.back() == '.' || temp.back() == '?' || temp.back() == '!' || temp.back() == '-' || temp.back() == '"' || temp.back() == ';' || temp.back() == ':' || temp.back() == 71)
					{
						temp.pop_back();
					}
					else if (temp.front() == '"')
					{
						temp = temp.substr(1).append(temp.substr(0, 1));
					}
					else
					{
						foo = true;
					}
				}
				else
				{
					foo = true;
				}

			}
			//copy2.push_back(str);
			if (temp != "")
			{
				words.push_back(temp);
				copy.push_back(temp);
			}
			foo = false;
		}
	}

	void numWords();
	void topThirtyWords();
	void totalNumWords();
	char foo;






private:

	vector<string> words;
	fstream inFile;
	vector<string> copy;
	vector<string> copy2;
	//string str;
	//bool icompare_pred(unsigned char a, unsigned char b);
	//bool icompare(string const& a, string const& b);

};





void countwords::numWords()
{

	int steps = 0;

	steps++;

	cout << "Number of Words is" << steps << endl;
}

void countwords::topThirtyWords()
{
	int greater_word = 0;
	int steps = 0;
	int foo = 0;
	int blah;
	string str;
	string str2;
	int steps2 = 0;
	int high = copy.size();

	//cout << "the size of the speech is " << copy.size() << endl;

	for (int t = 30; t > 0; t--)
	{
		for (int r = 0; r < high; r++)
		{
			str = copy[r];
			for (int c = 0; c < high; c++)
			{
				if (foo != '-'  && foo != 39 && foo != '.' && foo != ',' && foo != ' ')
				{
					if (caseInsCompare(str, copy[c]))//str.compare(copy[c]) == 0)
					{
						steps++;
						//infile >> foo;

					}
				}
			}
			if (steps > greater_word)
			{

				greater_word = steps;

				str2 = str;

			}
			steps = 0;
		}

		for (int i = 0; i < copy.size(); i++)
		{
			
			if (caseInsCompare(str2, copy[i]))//str2.compare(copy[i]) == 0)
			{
				copy.erase(copy.begin() + i);
				steps2++;
				high = copy.size();
			}
		}

		cout << t << " ";
		cout << str2 << " " << greater_word << " " << steps2 << endl;

		greater_word = 0;




	}
}


void countwords::totalNumWords()
{
	int high = words.size();
	for (int c = 0; c <= high; c++)
	{
		for (int r = c + 1; r < words.size(); r++)
		{
			if (words[c].compare(words[r]) == 0)
			{
				words.erase(words.begin() + r);
				r--;
			}
		}
		high = words.size();
	}
	cout << "The total num words are: " << high << endl;

	/*for (int i = 0; i < high; i++)
	{
		cout << words[i] << " ";
	}*/
}












