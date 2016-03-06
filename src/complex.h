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

	//operator overloading
	friend ostream& operator<<(ostream& os, const complex& a);
	friend istream& operator>>(istream& is, complex& a);
	friend complex operator+(complex a, complex b);
	friend bool operator==(complex a, complex b);
	complex& operator=(const complex &cSource);

	//functions
	void setComplex(double a, double b);
	double ComplexGetVal();


private:
	double real;
	double imaginary;

};

//functions
complex ComplexFIn(istream& fin);							//Returns a complex number object from an istream object/file
complex ComplexAdd(istream& fin);							//Adds all complex numbers in a file


#endif /* COMPLEX_H_ */

//go over an expanding constructor
