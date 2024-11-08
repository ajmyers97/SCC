//some code structure borrowed from goo.gl/sscjSN
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :       CH10_Ex12                                   * 
//*                                                                     * 
//* Written by      : Allen J Myers, Michael Rearden, Robert Hanson     * 
//*                                                                     * 
//* Purpose         : To implement bookType.h                           * 
//*                                                                     * 
//* Inputs          : No input calls from user                          * 
//*                                                                     * 
//* Outputs         : Display of entry request on the system terminal   * 
//*                                                                     * 
//* Calls           : Does not have any external calls                  * 
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
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class bookType
{
	public:
		void setBookInfo(string title, string ISBN, string Publisher, int PublishYear,
			string auth[], double cost, int copies,
			int noAuthors);
		void setBookTitle(string s);
		void setBookISBN(string s);
		void setBookPrice(double cost);
		void setCopiesInStock(int noOfCopies);
		void printInfo() const;
		bool isISBN(string s) const;
		bool isTitle(string s) const;
		bool isAuthor(string s) const;
		void getBookTitle(string& s) const;
		void getBookISBN(string& s) const;
		double getBookPrice() const;
		bool isInStock() const;
		void makeSale();
		void printBookPrice() const;
		void printbookTitle() const;
		void printbookTitleAndISBN() const;
		void showQuantityInStock() const;
		void updateQuantity(int addBooks);
		bookType();
		bookType(string title, string ISBN, string Publisher, int PublishYear,
			string auth[], double cost, int copies,
			int noAuthors);
		~bookType();

	private:
		string bookTitle;
		string bookISBN;
		string bookPublisher;
		int bookPublishYear;
		string authors[4];
		double price;
		int quantity;
		int noOfAuthors;
};