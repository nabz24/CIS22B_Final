#pragma once
#include <iostream>
#include "Book.h"
using namespace std;

class Sport : public Book
{
private:
	std::string sport;


public:

	Sport() : Book()
	{

	};

	~Sport()
	{
		cout << "Sport Destructed" << endl;
	}

	Sport(string ISBN, std::string Title, std::string Author, std::string Publisher, int quantity, double wholeSaleCost, double RetailPrice, Date publishedIn,
		Date addedIn, string s) : Book(ISBN, Title, Author, Publisher, quantity, wholeSaleCost, RetailPrice, publishedIn, addedIn)
	{
		sport = s;
	};

	//accesors
	string getSport() const;

	//setter
	void setSport(string s);

};