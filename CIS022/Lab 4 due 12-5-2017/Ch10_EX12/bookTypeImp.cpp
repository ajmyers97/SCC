//implementation of bookType.h
//some code structure borrowed from goo.gl/sscjSN
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :       CH10_Ex12                                   * 
//*                                                                     * 
//* Written by      : Allen J Myers, Michael Rearden, Robert Hanson     *
//*					  Ryan Jeffrey										*
//*                                                                     * 
//* Purpose         : To implement the fucntions of bookType.h          * 
//*                                                                     * 
//* Inputs          : No input calls from user                          * 
//*                                                                     * 
//* Outputs         : Display of entry request on the system terminal   * 
//*                                                                     * 
//* Calls           : Calls to bookType.h                               * 
//*                                                                     * 
//* Structure       : BEGIN                                             * 
//*                        Straight line code no sub-processes          * 
//*                   STOP                                              * 
//*                        End of Program                               * 
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Change Log:                                                         * 
//*                         Revision                                    * 
//*       Date    Changed  Rel Ver Mod Purpose                          * 
//* 12/07/17      amyers15 000.000.000 Initial release of program       * 
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#include <iostream>
#include<string>
#include "bookType.h"
using namespace std;

void bookType::setBookInfo(std::string title, std::string ISBN, std::string Publisher, int PublishYear,
	string auth[4], double cost, double quantity, int noAuthors)
{
	bookTitle = title;
	bookISBN = ISBN;
	bookPublisher = Publisher;
	bookPublishYear = PublishYear;
	for (int i = 0; i < noAuthors; i++)
	{
		authors[i] = auth[i];
	}
	price = cost;	
	quantity = copies;
	noOfAuthors = noAuthors;
}

void bookType::setBookTitle(std::string s)
{
	bookTitle = s;
}
void bookType::setBookISBN(std::string s)
{
	bookISBN = s;
}

void bookType::setBookPrice(double cost)
{
	price = cost;
}

void bookType::setCopiesInStock(int noOfCopies)
{
	copies = noOfCopies;
}

void bookType::printInfo() const
{
	cout << "Title: " << bookTitle << endl;
	cout << "ISBN: " << bookISBN << endl;
	cout << "Publisher: " << bookPublisher << endl;
	cout << "Year: " << bookPublishYear << endl;
	cout << "Authors: ";
	for (int i = 0; i < 4; i++)
	{
		cout << authors[i] << " ";
	}
	cout << endl;
	cout << "Price: $" << price << endl;
	cout << "Quantity: " << quantity << endl;
	cout << "Number of Authors: " << noOfAuthors << endl;
}

bool bookType::isISBN(std::string s) const
{
	if (s == bookISBN)
		return true;
	else
		return false;
}

bool bookType::isTitle(std::string s) const
{
	if (s == bookTitle)
		return true;
	else
		return false;
}

bool bookType::isAuthor(std::string s) const
{
	for (int i = 0; i < noOfAuthors; i++)
	{
		if (s == authors[i])
			return true;
		else
			return false;
	}
	return 0;
}

void bookType::getBookTitle(std::string& s) const
{
	s= bookTitle;
	
}

void bookType::getBookISBN(std::string& s) const
{
	s= bookISBN;
}

double bookType::getBookPrice() const
{
	return price;
}

bool bookType::isInStock() const
{
	if (quantity != 0)
		return true;
	else
		return false;
}

void bookType::makeSale()
{
	bookTitle = "";
	bookISBN = "";
	bookPublisher = "";
	bookPublishYear = 0;
	authors[4] ="";
	price = 0;
	copies = 0;
	noOfAuthors = 0;
}

void bookType::printBookPrice() const
{
	cout << "Price: $" << price << endl;
}

void bookType::printbookTitle() const
{
	cout << "Title: " << bookTitle << endl;
}

void bookType::printBookTitleAndISBN() const
{
	cout << "Title: " << bookTitle << endl;
	cout << "ISBN: " << bookISBN << endl;
}

void bookType::showQuantityInStock() const
{
	cout << "Quantity: " << copies << endl;
}

void bookType::updateQuantity(int addBooks)
{
	quantity + addBooks;
}

bookType::bookType()
{
	
}

bookType::bookType(std::string title, std::string ISBN, std::string Publisher, int PublishYear,
	std::string auth[4], double cost, int quantity,
	int noAuthors)
{
	setBookInfo(title, ISBN, Publisher, PublishYear, auth, cost, quantity, noAuthors);
}

bookType::~bookType()
{

}



