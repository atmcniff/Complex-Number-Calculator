/*
 * complex.cpp
 *
 *  Created on: Feb 10, 2016
 *      Author: Austin McNiff
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include "complex.h"
#include "complexDB.h"
#include <stdio.h>      /* printf, fopen */
#include <stdlib.h>     /* exit, EXIT_FAILURE */
#include <cmath>
using namespace std;

complex::complex()
{
	real = 0;
	imaginary = 0;
}

complex::complex(double a, double b) :
		real(a), imaginary(b)
{

}

complex::~complex()
{
	// TODO Auto-generated destructor stub
}

istream& operator>>(istream& is, complex& a)
{
	double real = 0;
	double im = 0;
	char plusorminus = '\0';
	char ichar = '\0';
	complex complexNum(0, 0);
	string oneline;
	bool iPresent = false;

	getline(is, oneline);

	//check for invalid line
	for (int i = 0; i < (signed) oneline.length(); i++)
	{
		if ((isalpha(oneline[i]) && oneline[i] != 'i')
				|| (oneline[i] == 'i' && iPresent))
		{
			a = complexNum;	//ends if oneline is invalid
			return is;
		}
		if (oneline[i] == 'i' && !iPresent)
			iPresent = true;
	}

	//extracts oneline and stores in matching temp vars
	stringstream(oneline) >> real >> plusorminus >> im >> ichar;

	//initial checks
	if (oneline[0] == 'i')
	{
		real = 1;
		plusorminus = 'i';
	}
	else if (oneline[0] == '-' && oneline[1] == 'i')
	{
		real = -1;
		plusorminus = 'i';
	}

	//final check for output
	switch (plusorminus)
	{
	case '-':
		im = -im;
		break;
	case 'i':
		im = real;
		real = 0;
		break;
	case '\0':
		im = 0;
		break;
	}

	//stores object data in complexNum
	complexNum.setComplex(real, im);
	a = complexNum;
	//cout << complexNum << endl;	//comment out this line if you wish to hide all input from console
	return is;
}

ostream& operator<<(ostream& os, const complex& a)
{
//MUST DEAL WITH REAL:0 AND IMAGINARY:0,1,-1 EFFICIENTLY

//0 as the real number
	if (a.real == 0)
	{
		if (a.imaginary == 0)
		{
			os << 0;
			return os;
		}
		else if (a.imaginary == 1)
		{
			os << "i";
			return os;
		}
		else if (a.imaginary == -1)
		{
			os << "-i";
			return os;
		}
		else
		{
			os << a.imaginary << "i";
			return os;
		}
	}

	//0 is not the real number
	else
		os << a.real;

	if (a.imaginary >= -1)
	{
		if (a.imaginary == 0)
		{
			return os;
		}
		else if (a.imaginary == 1)
		{
			os << "+i";
			return os;
		}
		else if (a.imaginary == -1)
		{
			os << "i";
			return os;
		}
		else
		{
			os << "+" << a.imaginary << "i";
			return os;
		}
	}
	else
	{
		os << a.imaginary << "i";
		return os;
	}

	return os;
}

complex::complex(const complex &cSource)
{
	real = cSource.real;
	imaginary = cSource.imaginary;
}
complex& complex::operator=(const complex &cSource)
{
//copy
	real = cSource.real;
	imaginary = cSource.imaginary;

// return the existing object
	return *this;
}

void complex::setComplex(double a, double b)
{
	real = a;
	imaginary = b;
}

complex operator+(complex a, complex b)
{
	complex c(a.real + b.real, a.imaginary + b.imaginary);
	return c;

}

bool operator==(complex a, complex b)
{
	if (a.real == b.real && a.imaginary == b.imaginary)
		return true;
	else
		return false;
}

double complex::ComplexGetVal()
{
	return sqrt((this->real * this->real) + (this->imaginary * this->imaginary));
}

/*void ComplexMenu(string& finname, string& foutname)
{

	cin.ignore();
	cin.clear();
	fflush(stdin);
	ifstream fin;
	ofstream fout;
	complex sum(0, 0);

	string temp;
	 int lines=0;
	 fin.open(finname.c_str());
	 while(!fin.eof())
	 {
	 getline(fin, temp);
	 lines++;
	 cout<<"working";
	 }
	 fin.close();

	complexDB DB(20);
	string choice = "";

	while (choice[0] != '4')
	{
		fin.open(finname.c_str());
		if (fin.fail())
		{
			fin.close();
			cout << endl << "FAIL Input File: " << finname << "\nOutput File: "
					<< foutname << endl << endl;
			cout << "Enter Input File Name: ";
			cin.ignore();
			getline(cin, finname);
			choice = "";
			//~DB(); //destructor
			ComplexMenu(finname, foutname);		//necessary
			exit(1);
		}

		else
		{
			//fin.close();
			cout << endl << "Input File: " << finname << "\nOutput File: "
					<< foutname << endl << endl;

			fin.open(finname.c_str());
			readIn(DB, fin);
			fin.close();
		}
		cout
				<< "Enter Number for action\n**********************************************\n"
				<< "1\tCalculate Sum\n2\tChange Input File Name\n3\tChange Output File Name\n4\tExit Program\n";

		cin.ignore();
		cin.clear();
		fflush(stdin);
		cin >> choice;

		switch (choice[0])
		{

		//Change Input File Name
		case '1':
			cout << "Enter Input File Name: ";
			cin.ignore();
			getline(cin, finname);
			choice = "";
			//~DB();		//destructor
			ComplexMenu(finname, foutname);		//necessary
			exit(1);
			break;

			//Change Output File Name
		case '2':
			cout << endl << "Enter output File Name: ";
			cin.ignore();
			getline(cin, foutname);
			choice = "";
			break;

			//Calculate Sum
		case '3':
			fin.open(finname.c_str());

			if (fin.fail())
			{
				fin.close();
				cout << "Input file " << finname << " failed." << endl;
				choice = "";
				break;
			}

			else
			{
				fout.open(foutname.c_str());
				sum = ComplexAdd(fin);
				fout << sum;
				fin.close();
				fout.close();
				choice = "";

				break;
			}
			break; //this can be deleted, but I guess some people need that peace of mind? Idk...

			//list
		case '4':
			DB.listDB();
			break;

			//delete
		case '5':
			int choicedelete;
			cin >> choicedelete;
			complexDBDelete(choicedelete, DB);
			break;

			//save
		case '6':
			DB.saveDB(fout);
			break;

			//Exit Program
		case '7':
			cout << "Goodbye!" << endl;
			break;

		default:
			cout << "Invalid choice" << endl;
			choice = "";
			break;
		}
	}
}*/
