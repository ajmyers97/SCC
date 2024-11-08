//some code structure borrowed from goo.gl/sscjSN
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :       CH10_Ex12                                   * 
//*                                                                     * 
//* Written by      : Allen J Myers, Michael Rearden, Robert Hanson     * 
//*                                                                     * 
//* Purpose         : To simulate a bookstore                           * 
//*                                                                     * 
//* Inputs          : No input calls from user                          * 
//*                                                                     * 
//* Outputs         : Display of entry request on the system terminal   * 
//*                                                                     * 
//* Calls           : Calls to bookType.h/memberType.h                  * 
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
#include <iomanip>
#include "memberType.h"
#include "bookType.h"
using namespace std;
void getBookData(bookType books[], int& noOfBooks);
void getMemberData(memberType members[], int& noOfMembers);//custom made to complete
void printBookData(bookType books[], int noOfBooks);
void printMemberData(memberType members[], int noOfMembers);//custom made to complete
void purchaseBook();
void showMenu();

int main()
{
	cout<<"Allen Myers,Robert Hanson, Michael Rearden\t"<<"CH10_Ex12\t"<<"CH10_Ex12.exe"<<endl;
	bookType myBook[5];

	//int choice;
	int numberOfBooks = 0;

	getBookData(myBook, numberOfBooks);
	//printBookData(myBook, numberOfBooks);

	system("pause");

	return 0;
}

void getBookData(bookType books[], int& noOfBooks)
{
	string title;
	string ISBN;
	string publisher;
	int year;
	string authors[4];
	double price;
	int quantity;
	int numOfAuthors;
	ifstream infile;

	char ch;

	infile.open("BookData.txt");

	if (!infile)
	{
		cout << "Cannot open input file." << endl;
	}
	else
	{
		infile >> noOfBooks;
		infile.get(ch);
		for (int i = 0; i < noOfBooks; i++)
		{
			getline(infile, title);
			getline(infile, ISBN);
			getline(infile, publisher);
			infile >> year >> price >> quantity >> numOfAuthors;
			for (int j = 0; j < numOfAuthors; j++)
			{
				getline(infile, authors[j]);
			}
			infile.get(ch);

			books[i].setBookInfo(title, ISBN, publisher, year, authors, price, quantity, numOfAuthors);
		}
		
	}
}
void getMemberData(memberType members[], int& noOfMembers)//custom made to complete
{
	string ID, fName, lName;
	int bPurchased;
	double amount;
	ifstream infile;
	char ch;

	infile.open("MemberData.txt");

	if (!infile)
	{
		cout << "Cannot open input file." << endl;
	}
	else
	{
		infile>>noOfMembers;
		infile.get(ch);
		for(int i=0;i<noOfMembers;i++)
		{
			getline(infile,ID);
			getline(infile,fName);
			getline(infile, lName);
			infile>>bPurchased>>amount;
			infile.get(ch);
			members[].setMemberInfo(ID,fName,lName,bPurchased,amount);
		}
	}
}

void printBookData(bookType books[], int noOfBooks)
{
	for (int i = 0; i < noOfBooks; i++)
		books[i].printInfo();
}
void printMemberData(memberType members[], int noOfMembers)
{
	for(int i=0;i<noOfMembers;i++)
		members[i].printInfo();
}
void purchaseBook()
{

}


void showMenu()
{
	cout << "Welcome to Rock's Book Store" << endl;
	cout << "To make a selection enter the number and press enter" << endl;
	cout << "1: Print a list of books" << endl;
	cout << "2: Print a list of books and ISBN numbers" << endl;
	cout << "3: Print a list of members by ID" << endl;
	cout << "4: Purchase a book" << endl;
	cout << "5: To print members data" << endl;
	cout << "9: Exit the program." << endl;
}