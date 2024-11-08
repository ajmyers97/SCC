//implementation of bookType.h
//some code structure borrowed from goo.gl/sscjSN
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :       CH10_Ex12                                   * 
//*                                                                     * 
//* Written by      : Allen J Myers, Michael Rearden, Robert Hanson     * 
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
#include "memberType.h"
#include "bookType.h"
using namespace std;

void bookType::setBookInfo(string title, string ISBN, string Publisher, int PublishYear,
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

void bookType::setBookTitle(string s)
{
	bookTitle = s;
}
void bookType::setBookISBN(string s)
{
	bookISBN = s;}

void bookType::setBookPrice(double cost)
{
	price = cost;
}

void bookType::setCopiesInStock(int noOfCopies)
{
	quantity = noOfCopies;
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

bool bookType::isISBN(string s) const
{
	if (s == bookISBN)
		return true;
	else
		return false;
}

bool bookType::isTitle(string s) const
{
	if (s == bookTitle)
		return true;
	else
		return false;
}

bool bookType::isAuthor(string s) const
{
	for (int i = 0; i < noOfAuthors; i++)
	{
		if (s == authors[i])
			return true;
		else
			return false;
	}
}

void bookType::getBookTitle(string& s) const
{
	
}

void bookType::getBookISBN(string& s) const
{
	
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
	authors[4] = { 0 };
	price = 0;
	quantity = 0;
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

void bookType::printbookTitleAndISBN() const
{
	cout << "Title: " << bookTitle << endl;
	cout << "ISBN: " << bookISBN << endl;
}

void bookType::showQuantityInStock() const
{
	cout << "Quantity: " << quantity << endl;
}

void bookType::updateQuantity(int addBooks)
{
	//quantity + addBooks;
}

bookType::bookType()
{
	
}

bookType::bookType(string title, string ISBN, string Publisher, int PublishYear,
	string auth[4], double cost, int copies,
	int noAuthors)
{
	setBookInfo(title, ISBN, Publisher, PublishYear, auth, cost, copies, noAuthors);
}

bookType::~bookType()
{

}



