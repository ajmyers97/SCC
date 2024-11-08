//some code structure borrowed from goo.gl/sscjSN
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :       CH10_Ex12                                   * 
//*                                                                     * 
//* Written by      : Allen J Myers, Michael Rearden, Robert Hanson     *
//*					  Ryan Jeffrey										*
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
		void setBookInfo(std::string title, std::string ISBN, std::string Publisher, int PublishYear,
						string auth[4], double cost, double quantity, int noAuthors);
		void setBookTitle(std::string s);
		void setBookISBN(std::string s);
		void setBookPrice(double cost);
		void setCopiesInStock(int noOfCopies);
		void printInfo() const;
		bool isISBN(std::string s) const;
		bool isTitle(std::string s) const;
		bool isAuthor(std::string s) const;
		void getBookTitle(std::string& s) const;
		void getBookISBN(std::string& s) const;
		double getBookPrice() const;
		bool isInStock() const;
		void makeSale();
		void printBookPrice() const;
		void printbookTitle() const;
		void printBookTitleAndISBN() const;
		void showQuantityInStock() const;
		void updateQuantity(int addBooks);
		bookType();
		bookType(std::string title, std::string ISBN, std::string Publisher, int PublishYear,
			std::string auth[], double cost, int copies,int noAuthors);
		~bookType();

	private:
		std::string bookTitle;
		std::string bookISBN;
		std::string bookPublisher;
		int bookPublishYear;
		std::string authors[4];
		double price;
		int copies;
		int noOfAuthors;
};