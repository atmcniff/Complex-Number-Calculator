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
#include <stdio.h>      /* printf, fopen */
#include <stdlib.h>     /* exit, EXIT_FAILURE */
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

void ComplexMenu(string& finname, string& foutname)
{

	ifstream fin;
	ofstream fout;
	complex sum(0, 0);
	string choice = "";

	while (choice[0] != '4')
	{
		cout << endl << "Input File: " << finname << "\nOutput File: "
				<< foutname << endl << endl;

		cout
				<< "Enter Number for action\n**********************************************\n"
				<< "1\tCalculate Sum\n2\tChange Input File Name\n3\tChange Output File Name\n4\tExit Program\n";

		cin >> choice;

		switch (choice[0])
		{
		//Calculate Sum
		case '1':
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

			//Change Input File Name
		case '2':
			cout << "Enter Input File Name: ";
			cin.ignore();
			getline(cin, finname);
			choice = "";
			break;

			//Change Output File Name
		case '3':
			cout << endl << "Enter output File Name: ";
			cin.ignore();
			getline(cin, foutname);
			choice = "";
			break;

			//Exit Program
		case '4':
			cout << "Goodbye!" << endl;
			break;

		default:
			cout << "Invalid choice" << endl;
			choice = "";
			break;
		}
	}
}

complex ComplexFIn(istream& in)
{
	//temp variables
	double real = 0;
	double im = 0;
	char plusorminus = '\0';
	char ichar = '\0';
	complex complexNum(0, 0);
	string oneline;
	bool iPresent = false;

	getline(in, oneline);

	//check for invalid line
	for (int i = 0; i < (signed) oneline.length(); i++)
	{
		if ((isalpha(oneline[i]) && oneline[i] != 'i')
				|| (oneline[i] == 'i' && iPresent))
			return complexNum;	//ends if oneline is invalid
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
	cout << complexNum << endl;	//comment out this line if you wish to hide all input from console
	return complexNum;
}

/*void ComplexFOut(complex complexNum, ofstream fout)
 {

 //inserts object in output file
 fout << complexNum << endl;
 cout << "Complex number \"" << complexNum << "\" written to " << foutname
 << endl;
 fout.close();

 }*/

complex ComplexAdd(istream& fin)
{
	complex sum(0, 0);

	//open check
	cout << "Extracting complex numbers..."<<endl;
	while (!fin.eof())
	{
		sum = sum + ComplexFIn(fin);
	}

	cout << "Sum of all complex numbers is " << sum << endl;
	return sum;
}

