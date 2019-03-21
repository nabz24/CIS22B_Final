#pragma once
#include <iostream>
#include "Book.h"
using namespace std;

class History : public Book
{
private: 
	string timeInHisotryStart;
	string timeInHisotryEnd;


public: 

	History() : Book()
	{

	};

	~History()
	{
		cout << "TeamLeader Destructed" << endl;
	}

	History(string ISBN, std::string Title, std::string Author, std::string Publisher, int quantity, double wholeSaleCost, double RetailPrice, Date publishedIn,
		Date addedIn, string TimeInHistoryStart, string TimeInHistoryEnd) : Book(ISBN, Title, Author, Publisher, quantity, wholeSaleCost, RetailPrice, publishedIn, addedIn)
	{
		timeInHisotryStart = TimeInHistoryStart;
		timeInHisotryEnd = TimeInHistoryEnd;
	};

	History(const History &orig)
	{
		this->timeInHisotryStart = orig.timeInHisotryStart;
		this->timeInHisotryEnd = orig.timeInHisotryEnd;
	}

	History(std::string toParse) {
		std::string toTrunc = toParse;



		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		timeInHisotryStart = toTrunc.substr(toTrunc.find("|") + 1);
		cout << "8888888" << endl;
		cout << timeInHisotryStart  << endl;
		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		cout << "-------------" << endl;
		cout << toTrunc << endl;
		timeInHisotryEnd = toTrunc;
		//std::cout << ISBN;
	}

	//accesors
	string getTimeInHistoryStart() const;
	string getTimeInHistoryEnd() const;

	//setter
	void setTimeInHistoryStart(string T);
	void setTimeInHistoryEnd(string T);

};
