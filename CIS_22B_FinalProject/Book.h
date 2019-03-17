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
	std::string getISBN() const;
	std::string getTitle() const;
	std::string getAuthor() const;
	int getwholeSaleCost() const;
	double getRetailPrice() const;
	


	

	//mutators or setters
	void setISBN(std::string m);
	void setTitle(std::string t);
	void setRetailPrice(double price);
	void setAuthor(std::string auth);
	void setPublisher(std::string pub);

	


	//operating overloading
//    example
//    friend book operator+(car &left, car&right);


};




