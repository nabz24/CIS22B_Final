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
	Sport(const Sport &orig)
	{
		this->sport = orig.sport;
	}

	Sport(std::string toParse) : Book(toParse){
		std::string toTrunc = toParse;


		
		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		toTrunc = toTrunc.substr(toTrunc.find("|") + 1);
		cout << toTrunc << endl;

		sport = toTrunc;
		//std::cout << ISBN;
		cout << "yyyyyy" << endl;
	}

	//accesors
	string getSport() const;

	//setter
	void setSport(string s);

	string toString()
	{
		cout << "dfff" << endl;
		if (getISBN().size() != 0) {
			return (getISBN() + "|" + getTitle() + "|" + getAuthor() + "|" + getPublisher() + "|" + std::to_string(getQuantity()) + "|" + std::to_string(getRetailPrice()) + "|" + std::to_string(getwholeSaleCost()) + "|"
				+ (getPublished().getDay() < 10 ? "0" : "") + std::to_string(getPublished().getDay())
				+ (getPublished().getMonth() < 10 ? "0" : "") + std::to_string(getPublished().getMonth())
				+ (getPublished().getYear() < 10 ? "000" : (getPublished().getYear() < 100 ? "00" : (getPublished().getYear() < 1000 ? "0" : ""))) + std::to_string(getPublished().getYear()) + "|"
				+ (getAdded().getDay() < 10 ? "0" : "") + std::to_string(getAdded().getDay())
				+ (getAdded().getMonth() < 10 ? "0" : "") + std::to_string(getAdded().getMonth())
				+ (getAdded().getYear() < 10 ? "000" : (getAdded().getYear() < 100 ? "00" : (getAdded().getYear() < 1000 ? "0" : ""))) + std::to_string(getAdded().getYear()) + "|" + getSport());
		}
		return "";
	};
};