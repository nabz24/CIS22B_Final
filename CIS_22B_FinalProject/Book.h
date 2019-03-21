#pragma once
#include <iostream>
#include <string>
#include "Date.h"
class Book{
private:
	std::string ISBN;
	std::string title;
	std::string author;
	std::string publisher;
	int quantity;
	Date published;
	Date added;
	double wholeSaleCost;
	double retailPrice;
	//Date added


public:
	class InvalidInput
	{};
	//Constructor
	Book();
	Book(std::string ISBN, std::string Title, std::string Author, std::string Publisher, int quantity, double wholeSaleCost, double RetailPrice, Date publishedIn, Date addedIn);
	Book(const Book &orig);
	Book(std::string toParse);
	// Destructor
	~Book();

	// Accessor or getters
	inline std::string getISBN() const { return ISBN; };
	inline std::string getTitle() const { return title; }
	inline std::string getAuthor() const { return author; }
	inline std::string getPublisher() const { return publisher; }
	inline double getwholeSaleCost() const { return wholeSaleCost; }
	inline double getRetailPrice() const { return retailPrice; }
	inline int getQuantity() const {return quantity;}
	inline Date getPublished() const {return published;}
	inline Date getAdded() const {return added;}
	/*inline*/ 
	std::string toString();/*
		{	if(ISBN.size() != 0)
				return (ISBN + "|" + title + "|" + author + "|" + publisher + "|" + std::to_string(quantity) + "|"+ std::to_string(retailPrice) + "|"+ std::to_string(wholeSaleCost) + "|"
					+ (published.getDay() < 10 ? "0":"") + std::to_string(published.getDay())
					+ (published.getMonth() < 10 ? "0" : "") + std::to_string(published.getMonth())
					+ (published.getYear() < 10 ? "000" : (published.getYear() < 100 ? "00": (published.getYear() < 1000 ? "0" : ""))) + std::to_string(published.getYear()) + "|"
					+ (added.getDay() < 10 ? "0":"") + std::to_string(added.getDay())
					+ (added.getMonth() < 10 ? "0" : "") + std::to_string(added.getMonth())
					+ (added.getYear() < 10 ? "000" : (added.getYear() < 100 ? "00": (added.getYear() < 1000 ? "0" : ""))) + std::to_string(added.getYear()));
				return "";
			};
			*/
	/*
	std::string getISBN() const;
	std::string getTitle() const;
	std::string getAuthor() const;
	int getwholeSaleCost() const;
	double getRetailPrice() const;
	*/


	

	//mutators or setters
	inline void setISBN(std::string m) { ISBN = m; };
	inline void setTitle(std::string t) { title = t; };
	inline void setRetailPrice(double price) { retailPrice = price; };

	void setWholesale(double price) 
	{
		if (price >= 0.0)
		{
			wholeSaleCost = price;
		}
		else
			throw InvalidInput();
	};
	inline void setAuthor(std::string auth) { author = auth; };
	inline void setPublisher(std::string pub) { publisher = pub; };
	inline void setQuantity(int pub) { quantity = pub; };
	inline void setPublished(Date a) { published = a; };
	inline void setAdded(Date a) { added = a; };


	


	//inline void setAuthor(std::string auth);
	//void setPublisher(std::string pub);

	

	//operating overloading
//    example
//    friend book operator+(car &left, car&right);


};
