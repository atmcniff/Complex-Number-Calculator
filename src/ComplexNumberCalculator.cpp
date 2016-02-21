//============================================================================
// Name        : ComplexNumberCalculator.cpp
// Author      : Austin McNiff
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "complex.h"
#include <fstream>
using namespace std;

int main()
{
	string finname;
	string foutname;

	cout << "Enter Input File Name: ";
	getline(cin, finname);
	cout << endl << "Enter output File Name: ";
	getline(cin, foutname);

	//MENU
	ComplexMenu(finname, foutname);

	return 0;
}
