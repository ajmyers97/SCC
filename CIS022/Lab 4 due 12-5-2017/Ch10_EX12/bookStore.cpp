#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "bookType.h"
#include "memberType.h"
using namespace std;

void getBookData(bookType books[], int& noOfBooks);
void printBookData(bookType books[], int noOfBooks);
void getMembersData(memberType members[], int& count);
void printMembersData(memberType members[], int count);
void showMenu();
void makeSale(bookType books[],int bookCount,memberType members[], int memberCount, string ID, string ISBN);
void searchBookData(bookType books[], int bookCount, string ISBN,int& loc);
void searchMemberData(memberType members[], int memberCount,string ID, int& loc);

int main(){bookType books[1000];
	int numberOfBooks = 0;
	memberType storeMembers[500];
	int numberOfMembers = 0;
	int choice;
	int i;
	getBookData(books, numberOfBooks);
	getMembersData(storeMembers, numberOfMembers);
	cout << "\n----------------------LIST Of BOOKS----------------------\n";
	for (i = 0; i <numberOfBooks; i++)
		books[i].printBookTitleAndISBN();
	cout << endl;
	cout << "\n----------------------LIST Of MEMBERS----------------------\n";
	printMembersData(storeMembers, numberOfMembers);
	cout << "\n----------------------LIST Of Missing----------------------\n";
	makeSale(books, numberOfBooks, storeMembers, numberOfMembers, "00", "3-7908-1335-4");
	makeSale(books, numberOfBooks, storeMembers, numberOfMembers, "20", "zzzzzzzzzzzzz");
	cout << "\n----------------------Good Purchases----------------------\n";
	makeSale(books, numberOfBooks, storeMembers, numberOfMembers, "10", "3-7908-1335-4");
	cout << "\n";makeSale(books, numberOfBooks, storeMembers, numberOfMembers, "20", "3-7908-1335-4");
	cout << "\n";makeSale(books, numberOfBooks, storeMembers, numberOfMembers, "30", "3-7908-1335-4");
	cout << "\n----------------------LIST Of MEMBERS----------------------\n";
	printMembersData(storeMembers, numberOfMembers);
	return 0;
}
void getBookData(bookType books[], int& noOfBooks)
{
	string title;string ISBN;string Publisher;
	int PublishYear;
	string auth[4];
	double cost;
	int copies;
	int authorCount;
	int i, j;
	ifstream infile;
	char ch;infile.open("TestCh10-12BookData.txt");
	if (!infile)
	{
	cout << "Cannot open the input file." << endl;
	cout << "Exit the program" << endl;
	return;
	}
	infile >> noOfBooks;infile.get(ch);
		for (i = 0; i < noOfBooks; i++)
	{
		getline(infile, title);getline(infile,ISBN);getline(infile,Publisher);
		infile >> PublishYear >> cost >> copies >> authorCount;infile.get(ch);
		for (j = 0; j < authorCount; j++)getline(infile,auth[j]);
		books[i].setBookInfo(title, ISBN, Publisher,PublishYear, auth, cost, copies,authorCount);
}
}
void printBookData(bookType books[], int noOfBooks)
{
	int i;
	for (i = 0; i < noOfBooks; i++)
		{
			books[i].printInfo();
	cout << endl << "---------------------------------" << endl;
}
}
void getMembersData(memberType members[], int& count)
	{
		int i;
		string ID;
		string fName;
		string lName;
		int bookCount;
		double amount;
		ifstream infile;infile.open("TestCh10-12MbrData.txt");
		infile>>count;
		for (i = 0; i < count; i++)
			{
				infile >> ID >> fName >> lName >> bookCount >> amount;
			members[i].setMemberInfo(ID,fName,lName,bookCount,amount);
		}
	}
		
void printMembersData(memberType members[], int count)
		{
			int i;
			for (i = 0; i < count; i++)
				members[i].printInfo();
		}
void makeSale(bookType books[], int bookCount,memberType members[], int memberCount, string ID, string ISBN)
{
	double amountDue = 0;
	double bookPrice = 0;
	int booksBought;
	double discount = 0;
	int memberLoc;
	int bookLoc;
	cout << fixed << showpoint;cout << setprecision(2);
	searchBookData(books, bookCount, ISBN, bookLoc);
	if (bookLoc != -1)
		{
			if (books[bookLoc].isInStock())
				{
					bookPrice = books[bookLoc].getBookPrice();
					searchMemberData(members, memberCount, ID, memberLoc);
			if (memberLoc != -1)
				{
					booksBought = members[memberLoc].getBooksPurchased();
					if (booksBought >= 10)
							{
								bookPrice = bookPrice * 0.95;
								discount = members[memberLoc].getTotalAmountSpent() / 10;
								amountDue = bookPrice - discount;
								members[memberLoc].resetbooksBoughtAndAmount();
				cout << "Member Reward Please pay: $" << amountDue << endl;
			}
			else
				{
					members[memberLoc].purchaseBook(bookPrice * 0.95);
					cout << "Member Please pay: $" << bookPrice * 0.95 << endl;
				}
			}
			else cout << "Non Member    Please pay: $" << bookPrice << endl;
					books[bookLoc].makeSale();
				}
				else cout << "This book is currently out of stock" << endl;
		}
			else cout << "Sorry, The store does not carry this book" << endl;
}
void searchBookData(bookType books[], int bookCount, string ISBN,int& loc)
{
	int i;
	loc = -1;
	for (i = 0; i < bookCount; i++)
		if (books[i].isISBN(ISBN))
			{loc = i;
				break;
			}
			}
void searchMemberData(memberType members[], int memberCount,string ID, int& loc)
{
	int i;
	loc = -1;
	for (i = 0; i < memberCount; i++)
	if (members[i].isMemberID(ID))
		{
			loc = i;break;
		}
	}





