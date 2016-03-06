//============================================================================
// Name        : ComplexNumberCalculator.cpp
// Author      : Austin McNiff
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "complex.h"
#include "complexDB.h"
#include "menu.h"
#include <fstream>
using namespace std;

int main()
{
	string finname;
	string foutname;

	//enter input and output file names
	cout << "Enter Input File Name: ";
	getline(cin, finname);
	cout << endl << "Enter output File Name: ";
	getline(cin, foutname);

	//menu
	menu(finname, foutname);

//	ifstream fin;
//	ofstream fout;
//	fin.open("easy.txt");
//	fout.open("output.txt");
//	complexDB db(20);
//	readIn(db, fin);
//	cout<<db<<endl;
//	cout<<db<<endl;

//	cout<<"hi"<<endl;
//	int a[]={4,2,1,7,2,9,5};
//	int b[7] = {0};
//	int least;
//
//	for(int i = 0; i<7; i++)
//	{
//		least = a[i];
//		for(int j = i+1; j<7; j++)
//		{
//			if(a[j]<least)least = a[j];
//		}
//		b[i] = least;
//	}
//
//	for(int i = 0; i<7; i++)
//	{
//		cout<<b[i]<<endl;
//	}

	return 0;
}
