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

#include <iostream>
#include "reportModule.h"
#include "Book.h"
#include "Date.h"

using namespace std;

void reportModule(Book arr[], int numbook)
{
	//creating copy of the book and date parameters
	int numBook = numbook;
	Book bookCopy[66];
	Date dateCopy[66];



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
			cout << "Information about the books will be printed below:" << endl;
			cout << "------------------------------------------------" << endl;
			for (int i = 0; i < numBook; i++)
			{
				cout << "The ISBN is: " << arr[i].getISBN() << endl;
				cout << "The title is :" << arr[i].getTitle() << endl;
				cout << "The author is: " << arr[i].getAuthor() << endl;
				cout << "The wholesale cost is: " << arr[i].getwholeSaleCost() << endl;
				cout << "The Quantity price is: " << arr[i].getQuantity() << endl << endl <<endl;
				
			}
		}

		//Inventory Wholesale Value
		if (choice == 2)
		{
			double total = 0;

			cout << "Title and wholesale value will be printed below:" << endl;
			cout << "------------------------------------------------" << endl;
			for (int i = 0; i < numBook; i++)
			{

				total += arr[i].getwholeSaleCost();
				cout << arr[i].getTitle() << " wholesale cost: " << arr[i].getwholeSaleCost() << endl;
			}
			cout << "Total Wholesale : $" << total << endl;
		}

		//Inventory Retail Value
		if (choice == 3)
		{
			double total = 0;
			cout << "               Retail Inventory Value          :" << endl;
			cout << "------------------------------------------------" << endl;
			for (int i = 0; i < numBook; i++)
			{
				cout << arr[i].getTitle() << "Retail price is:\t" << arr[i].getRetailPrice() << endl;
			}
			cout << "Total Retail : $" << total << endl;

		}



		//List by Quantity
		
		if (choice == 4)
		{
			
			//run a selection sort by quantity
			int size = numbook;			//this size should be the amount of books 
			int startScan, minIndex;
			int minValue;
			for (startScan = 0; startScan < (size - 1); startScan++)
			{
				minIndex = startScan;
				minValue = arr[startScan].getQuantity();
				for (int index = startScan + 1; index < size; index++)
				{
					if (arr[index].getQuantity() < minValue)
					{
						minValue = arr[index].getQuantity();
						minIndex = index;
					}
				}
				bookCopy[minIndex] = bookCopy[startScan];
				bookCopy[startScan].setQuantity(minValue);
			}

			for (int i = 0; i < numbook; i++)
			{
				cout << "Title and quantity of books will be printed below:" << endl << endl;

				cout << "The title is:\t" << arr[i].getTitle() << "\t";
				cout << "The quantity is:\t" << arr[i].getQuantity() << endl;
			}
		}

		//List by Cost
		if (choice == 5)
		{
			int size = 66;			//this size should be the amount of books 
			int startScan, minIndex;
			double minValue;
			for (startScan = 0; startScan < (size - 1); startScan++)
			{
				minIndex = startScan;
				minValue = bookCopy[startScan].getRetailPrice();
				for (int index = startScan + 1; index < size; index++)
				{
					if (bookCopy[index].getRetailPrice() < minValue)
					{
						minValue = bookCopy[index].getRetailPrice();
						minIndex = index;
					}
				}
				bookCopy[minIndex] = bookCopy[startScan];
				bookCopy[startScan].setRetailPrice(minValue);

				for (int i = 0; i < 6; i++)
				{
					cout << "Title and cost of books will be printed below:" << endl << endl;

					cout << "The title is:\t" << bookCopy[i].getTitle() << "\t";
					cout << "The cost is:\t" << bookCopy[i].getRetailPrice() << endl;
				}
			}

			//List by Age
			if (choice == 6)
			{
				int size = 66;			//this size should be the amount of books 
				int startScan, minIndex;
				int minValue;
				for (startScan = 0; startScan < (size - 1); startScan++)
				{
					minIndex = startScan;
					minValue = dateCopy[startScan].getYear();
					for (int index = startScan + 1; index < size; index++)
					{
						if (dateCopy[index].getYear() < minValue)
						{
							minValue = dateCopy[index].getYear();
							minIndex = index;
						}
					}
					dateCopy[minIndex] = dateCopy[startScan];
					dateCopy[startScan].setYear(minValue);


					for (int i = 0; i < 6; i++)
					{
						cout << "Title and release year of books will be printed below:" << endl << endl;

						cout << "The title is:\t" << bookCopy[i].getTitle() << "\t";
						cout << "The release year is:\t" << dateCopy[i].getYear() << endl;
					}
				}

				//BREAK
				if (choice == 7)
				{
					break;
				}
			}
		};


	}

}