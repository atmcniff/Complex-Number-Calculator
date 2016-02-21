/*
 * complex.h
 *
 *  Created on: Feb 10, 2016
 *      Author: Austin McNiff
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

//classes
class complex
{
public:
	complex();
	complex(double, double);
	virtual ~complex();

	complex(const complex &cSource); //copy constructor
	complex& operator=(const complex &cSource);
	void setComplex(double a, double b);

	//operator overloading
	friend ostream& operator<<(ostream& os, const complex& a);
	friend istream& operator>>(istream& is, const complex& a);
	friend complex operator+(complex a, complex b);
	friend bool operator==(complex a, complex b);

private:
	double real;
	double imaginary;

};

//functions
void ComplexMenu(string& finname, string& foutname);		//Menu run in main
complex ComplexFIn(istream& fin);							//Returns a complex number object from an istream object/file
complex ComplexAdd(istream& fin);							//Adds all complex numbers in a file


#endif /* COMPLEX_H_ */

//go over an expanding constructor
