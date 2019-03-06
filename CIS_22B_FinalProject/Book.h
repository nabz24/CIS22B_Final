#pragma once
#include <iostream>
#include <string>

class Book
{
private:
	std::string ISBN;
	std::string title;
	std::string author;
	std::string publisher;
	int quantity;
	double wholeSaleCost;
	double retailPrice;
	//Date added


public:
	//Constructor
	Book() {

	};
	Book(std::string ISBN, std::string Title, std::string Author, std::string Publisher, int quantity, double wholeSaleCost, double RetailPrice);
	Book(const Book &orig);

	// Destructor
	~Book();

	// Accessor or getters
	std::string getISBN() const { return ISBN; };
	std::string getTitle() const { return Title; }
	std::string getAuthor() const { return Author; }
	int getwholeSaleCost() const { return wholeSaleCost; }
	double getRetailPrice() const { return RetailPrice; }
	int

	//The accessor for the interator
	static int getBookCount() { return quantity; }

	//mutators or setters
	void setISBN(std::string m);
	void setTitle(std::string);
	void setRetailPrice(double);
	void setAuthor(double);
	void setPublisher(double);

	//


	//operating overloading
//    example
//    friend book operator+(car &left, car&right);


};




