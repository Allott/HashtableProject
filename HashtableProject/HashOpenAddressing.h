#pragma once
#include <iostream>
#include <string>
using namespace std;

class HashOpenAddressing
{
public:
	HashOpenAddressing();
	HashOpenAddressing(int size);
	~HashOpenAddressing();
	void Insert(int k, string s);
	void Delete(int k, string s);
	int SearchSpeed(int k, string s);
	bool Search(int k, string s);
	string Showtable();

private:
	struct Bucket {
		string data;
		bool deleted;
	};

	int HashFunctionDivision(int k);
	int HashFunctionMultiplication(int k);

	int LinearProbing(int k, int p);
	int QuadraticProbing(int k, int p);//finish this
	int DoubleHashProbing(int k, int p);//finish this

	int m;//size of table
	int mMinus; //m - 1
	const double a = 0.6180339887; //constant for multiplication method (justify pick later)

	Bucket* table = NULL;
};

