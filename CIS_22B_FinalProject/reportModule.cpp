/*
	Pseudocode
	----------------------------
	Produces 6 reports
	1. Inventory List - just lists all the books and information
	in the database.
	2. Inventory Wholesale Value - sorts books in the database
	by price
	3. Inventory Retail Value - Prints name and retail price of
	all books in database
	4. List by Quantity - sorts books by quantity, most first
	5. List by Cost - sort books by retail price, expensive first
	6. List by Age - sorts books by purchase date, recent first


	Build a while look to keep module running until user quits it
		If choose option 1. -> Inventory List
			-calls and prints everything stored in book class

		If choose option 2. -> Inventory Wholesale Value
			-calls and prints name of book and wholesale value
			-prints total wholesale value of all books

		If choose option 3. -> Inventory Retail Value
			-calls and prints name of book and retail value
			-prints total retail value of all books

		If choose option 4. -> List by Quantity
			-use sorting algorithm to sort  books by quantity
			-print quantity and name, most first

		If choose option 5. -> List by Cost

			-use sorting algorithm to sort  books by wholesale
			cost
			-print wholesale cost and name, expensive first

		If choose option 6. -> List by Age
			-use sorting algorithm to sort  books by purchase
			date
			-print date and name, oldest first

		If choose option 7. -> BREAK
*/
#pragma once
#include <iostream>
#include "reportModule.h"
#include "Book.h"

using namespace std;

void reportModule(Book arr[]) {
	int choice = 0;

	while (choice != 7)
	{
		cout << "The Reports Module produces 6 reports. Choose the one that best fits your needs. " << endl;
		cout << "---------------------------------------------------------------------------------" << endl;
		cout << "1. Inventory List - just lists all the books and information in the database." << endl;
		cout << "2. Inventory Wholesale Value - sorts books in the database by price" << endl;
		cout << "3. Inventory Retail Value - Prints name and retail price of all books in database" << endl;
		cout << "4. List by Quantity - sorts books by quantity, most first" << endl;
		cout << "5. List by Cost - sort books by retail price, expensive first" << endl;
		cout << "6. List by Age - sorts books by purchase date, recent first" << endl;
		cout << "7. End the program. " << endl;

		cin >> choice;

		//If choose option 1. -> Inventory List
		if (choice == 1)
		{
			for (int i = 0; i < 6; i++)
			{
				cout << "Information about the books will be printed below:" << endl << endl;

				cout << "The ISBN is:\t" << arr[i].getISBN() << endl;
				cout << "The title is:\t" << arr[i].getTitle() << endl;
				cout << "The author is:\t" << arr[i].getAuthor() << endl;
				cout << "The wholesale cost is:\t" << arr[i].getwholeSaleCost() << endl;
				cout << "The retail price is:\t" << arr[i].getRetailPrice() << endl;
			}
		}

		//Inventory Wholesale Value
		if (choice == 2)
		{
			for (int i = 0; i < 6; i++)
			{
				cout << "Title and wholesale value will be printed below:" << endl << endl;

				cout << "The title is:\t" << arr[i].getTitle() << endl;
				cout << "The wholesale cost is:\t" << arr[i].getwholeSaleCost() << endl;
			}

		}

		//Inventory Retail Value
		if (choice == 3)
		{
			for (int i = 0; i < 6; i++)
			{
				cout << "Title and retail value will be printed below:" << endl << endl;

				cout << "The title is:\t" << arr[i].getTitle() << endl;
				cout << "The retail price is:\t" << arr[i].getRetailPrice() << endl;
			}

		}

		//List by Quantity
		if (choice == 4)
		{


		}

		//List by Cost
		if (choice == 5)
		{


		}

		//List by Age
		if (choice == 6)
		{


		}

		//BREAK
		if (choice == 7)
		{
			break;
		}
		
	}
		


};