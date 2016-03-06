/*
 * menu.cpp
 *
 *  Created on: Mar 2, 2016
 *      Author: AustinMcnipps
 */

#include "menu.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "complex.h"
#include "complexDB.h"
#include <stdio.h>      /* printf, fopen */
#include <stdlib.h>     /* exit, EXIT_FAILURE */
#include <cmath>

void menu(string& finname, string& foutname)
{

	ifstream fin;
	ofstream fout;
	complex sum(0, 0);
	complex temp(0,0);

	complexDB DB(20);
	char choice;

	fin.open(finname.c_str());
	if (fin.fail())
	{
		fin.close();
		cout << endl << "FAIL Input File: " << finname << "\nOutput File: "
				<< foutname << endl << endl;
		cout << "Enter Input File Name: ";
		cin.ignore();
		getline(cin, finname);
		menu(finname, foutname);		//necessary
		exit(1);
	}

	else
	{
		readIn(DB, fin);
		fin.close();
		while (choice != '8')
		{

			cout << endl << "Input File: " << finname << "\nOutput File: "
					<< foutname << endl << endl;
			cout
					<< "Enter Number for action\n**********************************************\n"
					<< "1\tChange Input File Name\n2\tChange Output File Name\n3\tCalculate Sum\n4\tList Complex Numbers \n5\tDelete a Complex Number \n6\tAdd a Complex Number \n7\tSave numbers to an Output File \n8\tExit Program\n";

			/*cin.ignore();
			 cin.clear();
			 fflush(stdin);*/
			cin >> choice;

			switch (choice)
			{

			//Change Input File Name
			case '1':
				cout << "Enter Input File Name: ";
				cin.ignore();
				getline(cin, finname);
				//choice = "";
				//~DB();		//destructor
				menu(finname, foutname);		//necessary
				exit(1);
				break;

				//Change Output File Name
			case '2':
				cout << endl << "Enter output File Name: ";
				cin.ignore();
				getline(cin, foutname);

				break;

			case '3':
				sum = CalculateSum(DB);
				cout << CalculateSum(DB) << endl;
				break; //this can be deleted, but I guess some people need that peace of mind? Idk...

				//list
			case '4':
				listDB(DB);
				break;

				//delete
			case '5':
			{
				int choicedelete;
				cout
						<< "Enter a number for which complex number to delete (use the list function to see all): "
						<< endl;
				cin >> choicedelete;
				complexDBDelete(DB, choicedelete);
				break;
			}

				//Add
			case '6':
			{
				cout << "Enter a real number: " << endl;
				double real=0;
				cin >> real;
				cout << "Enter an imaginary number: " << endl;
				double imaginary=0;
				cin >> imaginary;
				complex newc(real, imaginary);
				complexDBAdd(DB, newc);
				break;
			}
				//save
			case '7':
				cout << "Writing to " << foutname << endl;
				fout.open(foutname.c_str());
				saveDB(DB, fout);
				fout.close();

				break;

				//Exit Program
			case '8':
				cout << "Goodbye!" << endl;
				break;

			default:
				cout << "Invalid choice" << endl;
				break;
			}
		}
	}
}

