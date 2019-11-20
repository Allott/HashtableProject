#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

class HashChaining
{
public:
	HashChaining();
	HashChaining(int size);
	~HashChaining();
	void Insert(int k, string s);
	void Delete(int k, string s);
	int SearchSpeed(int k, string s);
	bool Search(int k, string s);
	string Showtable();

private:
	struct Bucket {
		//int value;//do i need this?
		list<string> data = {};
	};

	int HashFunctionDivision(int k);
	int HashFunctionMultiplication(int k);

	int m;//size of table
	int mMinus; //m - 1
	const double a = 0.6180339887; //constant for multiplication method (justify pick later)

	Bucket* table = NULL;
};

