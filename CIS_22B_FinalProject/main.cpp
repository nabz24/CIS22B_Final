#include <iostream>
#include <iomanip>
#include "Book.h"
#include <string>
#include<fstream>
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
	/*
	Book Becoming("9781524763138", "Becoming", "Michelle Obama", "Crown Publishing Group", 5, 15.00, 19.50);
	Book WhereTheCrawdadsSing("9780735219090", "Where the Crawdads Sing", "Delia Owens", "Penguin Publishing Group", 5, 10.00, 15.60);
	Book YouAreMyHappy("9780062931030", "You Are My Happy", "Hoda Kotb, Suzie Mason(Illustrator)", "HarperCollins Publishers", 5, 10.56, 17.09);
	Book TheUmbrellaAcademy("9781593079789", "The Umbrella Academy, Volume 1: Apocalypse Suite", "Gerard Way, Gabriel Ba (Artist)", "Dark Horse Comics", 5, 9.50, 11.90);
	Book TheMeullerReport("9781510750166", "The Meuller Report", "Robert S. Mueller III", "Skyhorse", 5, 10.56, 17.09);
	*/
	//Sport sam("12345", "eqdedf", "ewdwdf", "ewre", 4, 3.3, 2.2, Date("01022019"), Date("01022019"), "soccer");
	//History ale("12345", "eqdedf", "ewdwdf", "ewre", 4, 3.3, 2.2, Date("01022019"), Date("01022019"), "343222");

	//cout << ale.getTimeInHistory() << endl;
	Book* arr = readFile("DATA.txt");
	int selection;
	int numBooks;
	string textIn;
	selectionSort(arr, 4);
	
	for (int i = 0; i < 4; i++)
	{
		cout << arr[i].getISBN() << endl;
	}
	
	//cout << arr[0].toString() << endl;

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
		else if (selection == 2)
		{
			for (int a = 0; a < 2; a++)
				cout << a + 1 << ":" << arr[a].getTitle() << ":" << arr[a].getQuantity() << endl;
			do {
				cout << "Enter Book to change quantity:";
				cin >> numBooks;
				numBooks--;
			} while (!(numBooks < 2 && numBooks >=0));
			do {
				cout << "Enter new quantity:";
				cin>>selection;
			} while (!(selection >= 0));

			arr[numBooks].setQuantity(selection);
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
		cout << parseText << endl;
		int st = count_underscores(parseText);
		cout << st << endl;
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