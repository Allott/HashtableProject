#include "stdafx.h"
#include "HashOpenAddressing.h"


HashOpenAddressing::HashOpenAddressing()
{
}

HashOpenAddressing::HashOpenAddressing(int size)
{
	m = size;
	mMinus = m - 1;
	table = new Bucket[size];
	for (size_t i = 0; i < m; i++)
	{
		table[i].data = "";
		table[i].deleted = false;
	}
}

HashOpenAddressing::~HashOpenAddressing()
{
}

void HashOpenAddressing::Insert(int k, string s)
{
	for (size_t i = 0; i < m; i++)
	{
		int x = QuadraticProbing(k, i);

		if (table[x].data == "" || table[x].deleted == true)
		{
			table[x].data = s;
			table[x].deleted = false;
			break;
		}

	}
	//condition if failed?
}

void HashOpenAddressing::Delete(int k, string s)
{
	for (size_t i = 0; i < m; i++)
	{
		int x = QuadraticProbing(k, i);

		if (table[x].data == s && table[x].deleted == false)
		{
			table[x].deleted = true;
			break;
		}
	}

	//condition if failed?
}

int HashOpenAddressing::SearchSpeed(int k, string s)
{
	for (size_t i = 0; i < m; i++)
	{
		int x = QuadraticProbing(k, i);

		if (table[x].data == s)
		{
			return i + 1;//return number of additional probes
		}
	}

	return -1;//if not found return -1
}

bool HashOpenAddressing::Search(int k, string s)
{
	for (size_t i = 0; i < m; i++)
	{
		int x = QuadraticProbing(k, i);

		if (table[x].data == s)
		{
			return true;//return number of additional probes
		}
	}

	return false;//if not found return -1
}


string HashOpenAddressing::Showtable()
{
	string o = "";

	for (size_t i = 0; i < m; i++)
	{
		o.append("[");
		o.append(std::to_string(i));
		o.append(",");
		o.append(std::to_string(table[i].deleted));
		o.append("] = ");
		o.append(table[i].data);
		o.append("\r\n");
	}
	return o;
}

int HashOpenAddressing::HashFunctionDivision(int k)
{
	return k % m;
}

int HashOpenAddressing::HashFunctionMultiplication(int k)
{
	return floor(m * (k*a - floor(k*a)));
}

int HashOpenAddressing::LinearProbing(int k, int p)
{
	return (HashFunctionMultiplication(k) + p) % m;
}

int HashOpenAddressing::QuadraticProbing(int k, int p)
{
	return (HashFunctionMultiplication(k) + (p * p)) % m;
}

int HashOpenAddressing::DoubleHashProbing(int k, int p)
{
	int h1 = HashFunctionDivision(k);
	int h2 = 1 + (k % mMinus);
	int h3 = h1 + (p * h2);
	return h3 % m;
}