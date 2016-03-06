/*
 * complexDB.cpp
 *
 *  Created on: Feb 27, 2016
 *      Author: AustinMcnipps
 */

#include "complexDB.h"
#include "complex.h"
#include <stddef.h>
#include<cstddef>
#include<cstdlib>

complexDB::complexDB()
{
	max_size = 0;
	size = 0;
}

complexDB::~complexDB()
{
	delete[] complexArr;
}

complexDB::complexDB(int max)
{
	max_size = max;
	size = 0;
}

ostream& operator<<(ostream& os, const complexDB& a)
{
	int dbsize = a.size;
	for (int i = 0; i < dbsize - 1; i++)
	{
		os << i + 1 << ":\t" << a.complexArr[i] << endl;
	}
	if (dbsize > 0)
		os << dbsize << ":\t" << a.complexArr[dbsize - 1];
	return os;
}

void readIn(complexDB& db, istream& fin)
{
	complex temp(0, 0);
	int i = 0;
	while (!fin.eof())
	{
		fin >> temp;
		db.complexArr[i] = temp;
		db.size++;
		i++;
	}
}

void listDB(complexDB& db)
{
	complex temp(0, 0);
	temp = db.complexArr[0];
	for (int i = 0; i < db.size; i++)
	{
		for (int j = i + 1; j < db.size; j++)
		{
			//puts in ascending order
			if (db.complexArr[j].ComplexGetVal()
					< db.complexArr[i].ComplexGetVal())
			{
				temp = db.complexArr[i];
				db.complexArr[i] = db.complexArr[j];
				db.complexArr[j] = temp;
			}
		}
	}
	int dbsize = db.size;
	for (int i = 0; i < dbsize - 1; i++)
	{
		cout << i + 1 << ":\t" << db.complexArr[i] << endl;
	}
	if (dbsize > 0)
		cout << dbsize << ":\t" << db.complexArr[dbsize - 1];
}

void saveDB(complexDB& db, ofstream& fout)
{
	complex temp(0, 0);
	temp = db.complexArr[0];
	for (int i = 0; i < db.size; i++)
	{
		for (int j = i + 1; j < db.size; j++)
		{
			//puts in ascending order
			if (db.complexArr[j].ComplexGetVal()
					< db.complexArr[i].ComplexGetVal())
			{
				temp = db.complexArr[i];
				db.complexArr[i] = db.complexArr[j];
				db.complexArr[j] = temp;
			}
		}
	}
	int dbsize = db.size;
	for (int i = 0; i < dbsize - 1; i++)
	{
		fout << db.complexArr[i] << endl;
	}
	if (dbsize > 0)
		fout << db.complexArr[dbsize - 1];
}

void complexDBDelete(complexDB& a, int choicedelete)
{
	int size = a.size;

	if (choicedelete <= size && choicedelete>0)
	{
		complex none(0, 0);
		a.complexArr[choicedelete - 1] = none;

		for (int i = choicedelete - 1; i < size - 1; i++)
		{
			a.complexArr[i] = a.complexArr[i + 1];
		}
		a.complexArr[size] = none;

		a.size--;
	}

	else cout<<"Invalid choice.\n";

}

void complexDBAdd(complexDB& DB, complex& newcomplex)
{
	//execute if there is room to add a new complex number
	if (DB.size < DB.max_size)
	{
		DB.complexArr[DB.size] = newcomplex;
		DB.size++;
	}

	else
		cout << "Not enough memory." << endl;
}

complex CalculateSum(complexDB& db)
{
	complex sum(0, 0);

	int i = 0;
	while (i < db.size)
	{
		sum = sum + db.complexArr[i];
		i++;
	}

	return sum;
}

