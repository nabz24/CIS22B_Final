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
void DisplayTotalMenu(double Total);
void selectionSort(Book array[], int size);
Book *readFile(string fileName);
void writeFile(string fileName, Book* data);
int count_underscores(string s);



int main() {
	
	Book* arr = readFile("DATA.txt");
	int selection;
	int numBooks = 3;
	string textIn;
	selectionSort(arr, 26);
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

					cout << isbn << endl;
					position = binarySearch(arr, 5, isbn);
					cout << position << endl;
					cout << arr[position].getRetailPrice() << endl;
					total += arr[position].getRetailPrice();
					arr[position].setQuantity(arr[position].getQuantity() - 1);
					receipt[count] = arr[position].getTitle();
					count++;


				}

			} while (isbn != "Q");


			DisplayTotalMenu(total);




		}
		else if(selection == 2)
		{
			cout << "Current Inventory:\n";
			cout << "1:ISBN|2:TITLE|3:AUTHOR|4:PUBLISHER|5:QUANTITY|6:WHOLESALE COST|7:RETAIL PRICE|8:DATE PUBLISHED|9:DATE ADDED\n";
			cout << "-------------------------------------------------------------------------------------------------------------\n";
			for (int a = 0; a < 3; a++)
				cout << a + 1 << ":" << arr[a].toString() << endl;
			cout << "Enter Book to edit (select book 0 to make a new book):";
			cin >> bookToEdit;
			if (bookToEdit == 0) {
				cout << "Enter the string representation:\n";
				cin.clear(); 
				cin.ignore();
				getline(cin,textIn);
				arr[numBooks] = Book(textIn);
			}
			else {
				do {
					cout << "Enter the parameter number you wish to change (or 0 to exit):";
					cin >> selection;
					switch (selection) {
					case 0:
						cout << "ok bye"; break;
					case 1:
						cout << "enter ISBN:"; cin >> textIn; arr[bookToEdit].setISBN(textIn); break;
					case 2:
						cout << "enter Title:"; cin >> textIn; arr[bookToEdit].setTitle(textIn); break;
					case 3:
						cout << "enter Author:"; cin >> textIn; arr[bookToEdit].setAuthor(textIn); break;
					case 4:
						cout << "enter Publisher:"; cin >> textIn; arr[bookToEdit].setPublisher(textIn); break;
					case 5:
						cout << "enter Quantity:"; cin >> textIn; arr[bookToEdit].setQuantity(stoi(textIn)); break;
					case 6:
						cout << "enter WholeSale Cost:"; cin >> textIn; arr[bookToEdit].setWholesale(stod(textIn)); break;
					case 7:
						cout << "enter Retail Price:"; cin >> textIn; arr[bookToEdit].setRetailPrice(stod(textIn)); break;
					case 8:
						cout << "enter Date Published:"; cin >> textIn; arr[bookToEdit].setPublished(Date(textIn)); break;
					case 9:
						cout << "enter Date Added:"; cin >> textIn; arr[bookToEdit].setAdded(Date(textIn)); break;
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
	cout << "Please enter ISBN of book:" << endl;


	

};

void DisplayTotalMenu(double Tot)
{
	double total = Tot;
	double totalTax = total * .087;
	double tax_included_price = total * 1.087;
	cout << "                     Total" << endl;
	cout << "==============================================================" << endl;
	cout << "The sub total is $"<< total << endl;
	cout << "The total tax is $" << totalTax << endl;
	cout << "The total is $" <<  tax_included_price << endl;
	




};

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
		array[startScan].setISBN(minValue);
	}
}
Book* readFile(string fileName) {  //----MUST BE DELETED--MUST BE DELETED--MUST BE DELETED--MUST BE DELETED--MUST BE DELETED--MUST BE DELETED
	Book* ans = new Book[128];
	int tmp = 0;
	ifstream reader;
	reader.open(fileName);
	string parseText = "";
	
	while (getline(reader, parseText)) {
		int st = count_underscores(parseText);
		if (st == 8) 
		{
			ans[tmp++] = Book(parseText);
			//cout << parseText << endl;
		}
		else if(st == 9)
		{
			ans[tmp++] = Sport(parseText);

		}
		else
		{
			ans[tmp++] = History(parseText);
		}
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