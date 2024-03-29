// HashtableProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HashOpenAddressing.h"
#include "HashChaining.h"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;


int StringToID(string s) //converts a string into an id number
{
	int output = 0;

	for (size_t i = 0; i < s.length(); i++)
	{
		output += (int)s[i]; // for each character in string add its ASCII code to output
	}

	return output;
}

int main()
{
	string inputstring;
	ifstream inputfile("names.txt");
	HashOpenAddressing hashtableOA = HashOpenAddressing(1050);
	HashChaining hashtableC = HashChaining(1050);
	list<string> tableofnames = {};


	cout << "Loading data\n";

	if (inputfile.is_open())
	{
		while (inputfile >> inputstring)
		{
			tableofnames.push_back(inputstring);
		}
		inputfile.close();
	}
	else
	{
		cout << "Input File Missing";
		return 0;
	}

	cout << "Data loaded\n";

	cout << "TestingSearchSpeeds\n";

	ofstream outputfile1("output1.txt");
	ofstream outputfile2("output2.txt");
	if (outputfile1.is_open() && outputfile2.is_open())
	{
		for (list<string>::const_iterator iterator1 = tableofnames.begin(), end = tableofnames.end(); iterator1 != end; iterator1) {//for eachname in list name
			hashtableOA.Insert(StringToID(*iterator1), *iterator1); //add it to the hashtable
			hashtableC.Insert(StringToID(*iterator1), *iterator1);
			iterator1++;//increase here rather than in for as to set up the next for loop

			int count = 0;
			int searchtotal = 0;
			for (list<string>::const_iterator iterator2 = tableofnames.begin(), end = iterator1; iterator2 != end; iterator2++)
			{
				count++;
				int searchadd = hashtableOA.SearchSpeed(StringToID(*iterator2), *iterator2);
				if (searchadd != -1)
				{
					searchtotal += searchadd;
				}
				else
				{
					cout << "error item missing\n" << "Open Adressing Table:\n" << hashtableOA.Showtable();
					outputfile1.close();
					outputfile2.close();
					return 0;
				}
			}
			outputfile1 << ((double)searchtotal / count) << "\n";

			count = 0;
			searchtotal = 0;
			for (list<string>::const_iterator iterator2 = tableofnames.begin(), end = iterator1; iterator2 != end; iterator2++)
			{
				count++;
				int searchadd = hashtableC.SearchSpeed(StringToID(*iterator2), *iterator2);
				if (searchadd != -1)
				{
					searchtotal += searchadd;
				}
				else
				{
					cout << "error item missing\n" << "chaining Table:\n" << hashtableC.Showtable();
					outputfile1.close();
					outputfile2.close();
					return 0;
				}
			}
			outputfile2 << ((double)searchtotal / count) << "\n";

		}
		outputfile1.close();
		outputfile2.close();
	}
	else
	{
		cout << "Output File Missing";
		return 0;
	}

	cout << "Open Adressing Table:\n" << hashtableOA.Showtable();
	cout << "\nChaining Table:\n" << hashtableC.Showtable();
    return 0;
}

