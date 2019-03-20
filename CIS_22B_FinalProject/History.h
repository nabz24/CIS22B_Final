#pragma once
#include <iostream>
#include "Book.h"
using namespace std;

class History : public Book
{
private: 
	string timeInHisotry;


public: 

	History() : Book()
	{

	};

	~History()
	{
		cout << "TeamLeader Destructed" << endl;
	}

	History(string ISBN, std::string Title, std::string Author, std::string Publisher, int quantity, double wholeSaleCost, double RetailPrice, Date publishedIn,
		Date addedIn, string TimeInHistory) : Book(ISBN, Title, Author, Publisher, quantity, wholeSaleCost, RetailPrice, publishedIn, addedIn)
	{
		timeInHisotry = TimeInHistory;
	};

	//accesors
	string getTimeInHistory() const;

	//setter
	void setTimeInHistory(string T);

};