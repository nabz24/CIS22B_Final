#include <stdio.h>
#include "Book.h"



Book::Book(std::string ISB, std::string Ti, std::string Au, std::string Publish, int quant, double wholeSale, double retail) 
{
	ISBN = ISB;
	title = Ti;
	author = Au;
	publisher = Publish;
	quantity = quant;
	wholeSaleCost = wholeSale;
	retailPrice = retail;
	std::cout << "Constructor for object " << title << " with full initialization list called ..." << std::endl;
}

Book::Book(const car &orig)
{
	this->ISBN = orig.ISBN;
	this->title = orig.title;
	this->author = orig.author;
	this->publisher = orig.publisher;
	this->quantity = orig.quantity;
	this->wholeSaleCost = orig.wholeSaleCost;
	this->retailPrice = orig.retailPrice;
	std::cout << "Copy constuctor for object " << this->title << " with partial initialization list called ..." << std::endl;
}

Book::~Book()
{
	std::cout << make << " object is being destroyed ..." << std::endl;
}


//std::string Book::set
