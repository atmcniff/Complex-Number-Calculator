/*
 * complexDB.h
 *
 *  Created on: Feb 27, 2016
 *      Author: Austin McNiff
 */

#ifndef COMPLEXDB_H_
#define COMPLEXDB_H_
#include <fstream>
#include "complex.h"
using namespace std;
class complexDB {
public:
	complexDB();
	virtual ~complexDB();
	complexDB(int max);

	//operators
	friend ostream& operator<<(ostream& os, const complexDB& a);

	//functions
	friend void readIn(complexDB& a, istream& fin);
	friend void listDB(complexDB& a);
	friend void saveDB(complexDB& db, ofstream& fout);
	friend void complexDBDelete(complexDB& a, int choicedelete);
	friend void complexDBAdd(complexDB& DB, complex& newcomplex);
	friend complex CalculateSum(complexDB& db);

private:
	int max_size;
	int size;
	complex *complexArr = new complex[max_size];
};



#endif /* COMPLEXDB_H_ */
