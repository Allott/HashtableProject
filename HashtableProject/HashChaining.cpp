#include "stdafx.h"
#include "HashChaining.h"


HashChaining::HashChaining()
{
}

HashChaining::HashChaining(int size)
{
	m = size;
	mMinus = m - 1;
	table = new Bucket[size];
}

HashChaining::~HashChaining()
{
}

void HashChaining::Insert(int k, string s)
{
	int x = HashFunctionMultiplication(k);
	table[x].data.push_back(s);
}

void HashChaining::Delete(int k, string s)
{
	int x = HashFunctionMultiplication(k);
	table[x].data.remove(s);
}

int HashChaining::SearchSpeed(int k, string s)
{
	int x = HashFunctionMultiplication(k);
	int i = 0;
	for (list<string>::const_iterator iterator1 = table[x].data.begin(), end = table[x].data.end(); iterator1 != end; iterator1++)
	{
		i++;
		if (*iterator1 == s)
		{
			return i;
		}
	}

	return -1; //if not found
}


bool HashChaining::Search(int k, string s)
{
	int x = HashFunctionMultiplication(k);

	for (list<string>::const_iterator iterator1 = table[x].data.begin(), end = table[x].data.end(); iterator1 != end; iterator1++)
	{
		if (*iterator1 == s)
		{
			return true;
		}
	}

	return false; //if not found
}

string HashChaining::Showtable()
{
	string o = "";

	for (size_t i = 0; i < m; i++)
	{
		o.append("[");
		o.append(std::to_string(i));
		o.append("] = ");
		for (list<string>::const_iterator iterator1 = table[i].data.begin(), end = table[i].data.end(); iterator1 != end; iterator1++)
		{
			o.append(*iterator1 + ",");
		}
		o.append("\r\n");
	}
	return o;
}

int HashChaining::HashFunctionDivision(int k)
{
	return k % m;
}

int HashChaining::HashFunctionMultiplication(int k)
{
	return floor(m * (k*a - floor(k*a)));
}