#include <iostream>
#include <iomanip>
#include "Book.h"
#include <string>
#include <fstream>
#include "History.h"
#include "Sport.h"

using namespace std;

void DisplayMenu();
void CashierDisplayMenu();
int binarySearch(Book array[], int size, string value);
void DisplayTotalMenu(double Tot, string arr[], int coun);
void selectionSort(Book array[], int size);
Book *readFile(string fileName);
void writeFile(string fileName, Book* data);
int count_underscores(string s);
int searchList(Book list[], int numElems, string value);



int main() {
	
	Book y("1234567890123", "The Bible", "God", "King James", 4, 12.00, 21.34, Date(01, 01, 1600), Date(01, 01, 1600));
	Book x("1234567890124", "Skipper Ends Racism", "Kowalski", "Youtube", 4, 4.60, 12.45, Date(01, 02, 2019), Date(17, 03, 2019));
	Book a("1234", "Soccer Baiscs", "Sal Soo", "Youtube", 18, 5.40, 17.20, Date(01, 02, 2019), Date(17, 03, 2019));




	//Book* arr = readFile("DATA.txt");
	Book arr[3] = { y,x,a };
	int selection;
	int numBooks = 3;
	
	string textIn;
	int bookToEdit;

	
	do {
		DisplayMenu();
		cin >> selection;


		if (selection == 1)
		{

			string isbn;
			double total = 0.0;
			int position;
			string receipt[100];
			int count = 0;

			do
			{




				CashierDisplayMenu();
				cin >> isbn;
				if (isbn != "Q")
				{

					cout << "Book Found and added" << endl;
					position = searchList(arr, numBooks, isbn);
					//cout << position << endl;
					//cout << arr[position].getRetailPrice() << endl;
					total += arr[position].getRetailPrice();
					arr[position].setQuantity(arr[position].getQuantity() - 1);
					string receiptInput = "";
					receiptInput = arr[position].getTitle() + "     $" + to_string(arr[position].getRetailPrice());
					receipt[count] = receiptInput;
					count++;


				}

			} while (isbn != "Q");


			DisplayTotalMenu(total, receipt, count);




		}

		else if (selection == 2)
		{
			cout << "Current Inventory:\n";
			cout << "1:ISBN|2:TITLE|3:AUTHOR|4:PUBLISHER|5:QUANTITY|6:WHOLESALE COST|7:RETAIL PRICE|8:DATE PUBLISHED|9:DATE ADDED\n";
			cout << "-------------------------------------------------------------------------------------------------------------\n";
			for (int a = 0; a < numBooks; a++)
				cout << a + 1 << ":" << arr[a].toString() << endl;
			cout << "Enter Book to edit (select book 0 to make a new book):";
			cin >> bookToEdit;
			if (bookToEdit == 0) {
				cout << "Enter the string representation:\n";
				cin.clear();
				cin.ignore();
				getline(cin, textIn); cin.clear(); cin.ignore();
				arr[numBooks++] = Book(textIn);
			}
			else {
				do {
					cout << "Enter the parameter number you wish to change (or 0 to exit):";
					cin >> selection;
					switch (selection) {
					case 1:
						cout << "enter ISBN:";
						getline(cin, textIn); cin.clear(); cin.ignore();
						arr[bookToEdit].setISBN(textIn);
						break;
					case 2:
						cout << "enter Title:";
						getline(cin, textIn); cin.clear(); cin.ignore();
						arr[bookToEdit].setTitle(textIn);
						break;
					case 3:
						cout << "enter Author:";
						getline(cin, textIn); cin.clear(); cin.ignore();
						arr[bookToEdit].setAuthor(textIn);
						break;
					case 4:
						cout << "enter Publisher:";
						getline(cin, textIn); cin.clear(); cin.ignore();
						arr[bookToEdit].setPublisher(textIn);
						break;
					case 5:
						cout << "enter Quantity:";
						getline(cin, textIn); cin.clear(); cin.ignore();
						arr[bookToEdit].setQuantity(stoi(textIn));
						break;
					case 6:
						cout << "enter WholeSale Cost:";
						getline(cin, textIn); cin.clear(); cin.ignore();
						arr[bookToEdit].setWholesale(stod(textIn));
						break;
					case 7:
						cout << "enter Retail Price:";
						getline(cin, textIn); cin.clear(); cin.ignore();
						arr[bookToEdit].setRetailPrice(stod(textIn));
						break;
					case 8:
						cout << "enter Date Published:";
						getline(cin, textIn); cin.clear(); cin.ignore();
						arr[bookToEdit].setPublished(Date(textIn));
						break;
					case 9:
						cout << "enter Date Added:";
						getline(cin, textIn); cin.clear(); cin.ignore();
						arr[bookToEdit].setAdded(Date(textIn));
						break;
					default:
						selection = 0; break;
					}
				} while (selection != 0);


			}
		
		}

	} while (selection != 4);
	writeFile("PROOF.txt", arr);
	system("pause");

}

void DisplayMenu()
{
	cout << "==============================================================" << endl;
	cout << "                      Serendipity Boosellers" << endl;
	cout << "==============================================================" << endl;
	cout << "Please enter the number of the module you would like to use:" << endl;
	cout << "1. Cashier Module" << endl;
	cout << "2. Inventory Database Module" << endl;
	cout << "3. Report Module" << endl;
	cout << "4. Exit Program" << endl;
};

void CashierDisplayMenu()
{

	cout << "==============================================================" << endl;
	cout << "                     Cashier Module" << endl;
	cout << "==============================================================" << endl;
	cout << "Please enter ISBN of book or Q to quit:" << endl;


	

};

void DisplayTotalMenu(double Tot, string arr[], int coun)
{
	int count = coun;
	double total = Tot;
	double totalTax = total * .087;
	double tax_included_price = total * 1.087;
	cout << "                     Total" << endl;
	cout << "==============================================================" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << endl;
	}
	cout << "The sub total is $"<< total << std::setprecision(2) << fixed << endl;
	cout << "The total tax is $" << totalTax << std::setprecision(2) << fixed << endl;
	cout << "The total is $" << tax_included_price << std::setprecision(2) << fixed << endl;
	
};

int searchList(Book list[], int numElems, string value) 
	{
	int index = 0;      // Used as a subscript to search array
	int position = -1;  // To record position of search  value
	bool found = false; // Flag to indicate if value was found
	while (index < numElems&& !found)
	{
		if (list[index].getISBN() == value) // If the value is found 
		{ 
			found = true; // Set the flag 
			position = index; // Record the value's subscript
		}index++; // Go to the next element
	}return position; // Return the position, or -1
}

int binarySearch(Book array[], int size, string value) {
	int first = 0,             // First array element
		last = size - 1,       // Last array element
		middle,                // Mid point of search
		position = -1;         // Position of search value
	bool found = false;        // Flag
	while (!found && first <= last)
	{
		middle = (first + last) / 2;     // Calculate mid point
		if (array[middle].getISBN() == value)      // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle].getISBN() > value)  // If value is in lower half
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;           // If value is in upper half
		}
	}
	return position;
}

void selectionSort(Book array[], int size)
{
	int startScan, minIndex;
	string minValue;
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan].getISBN();
		for (int index = startScan + 1; index < size; index++)
		{
			if (array[index].getISBN() < minValue)
			{
				minValue = array[index].getISBN();
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}
Book* readFile(string fileName) {  //----MUST BE DELETED--MUST BE DELETED--MUST BE DELETED--MUST BE DELETED--MUST BE DELETED--MUST BE DELETED
	Book* ans = new Book[128];
	int tmp = 0;
	ifstream reader;
	reader.open(fileName);
	string parseText = "";
	
	while (getline(reader, parseText)) {
	
		cout << parseText << endl;
		ans[tmp++] = Book(parseText);
	
		
		//cout << parseText << endl;
		
	}
	reader.close();
	return ans;



};

void writeFile(string fileName, Book* data) { // DOES THE DELETE ---- DOES THE DELETE ---- DOES THE DELETE ---- DOES THE DELETE ----
	ofstream writer;
	cout << "rrrrr" << endl;
	writer.open(fileName);
	for (int a = 0; a < 128; a++)
		writer << data[a].toString() << endl;
	writer.close();
	delete[] data;
};


int count_underscores(string s) {
	int count = 0;

	for (int i = 0; i < s.size(); i++)
		if (s[i] == '|') count++;

	return count;
}