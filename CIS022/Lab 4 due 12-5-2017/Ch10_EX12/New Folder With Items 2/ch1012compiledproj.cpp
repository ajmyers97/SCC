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
void makeSale(bookType books[],int bookCount,memberType members[], int memberCount, std::string ID, std::string ISBN);
void searchBookData(bookType books[], int bookCount, std::string ISBN,int& loc);
void searchMemberData(memberType members[], int memberCount,std::string ID, int& loc);
void setBookInfo(std::string title, std::string ISBN, std::string Publisher, int PublishYear,
						std::string auth[4], double cost, double quantity, int noAuthors);
		void setBookTitle(std::string s);
		void setBookISBN(std::string s);
		void setBookPrice(double cost);
		void setCopiesInStock(int noOfCopies);
		void printInfo();
		bool isISBN(std::string s) ;
		bool isTitle(std::string s) ;
		bool isAuthor(std::string s) ;
		void getBookTitle(std::string& s) ;
		void getBookISBN(std::string& s) ;
		double getBookPrice() ;
		bool isInStock() ;
		void makeSale();
		void printBookPrice() ;
		void printbookTitle() ;
		void printBookTitleAndISBN() ;
		void showQuantityInStock() ;
		void updateQuantity(int addBooks);
		bookType ((std::string title, std::string ISBN, std::string Publisher, int PublishYear, std::string auth[], double cost, int copies,int noAuthors));
		std::string bookTitle;
		std::string bookISBN;
		std::string bookPublisher;
		int bookPublishYear;
		std::string authors[4];
		double price;
		int copies;
		int noOfAuthors;
		//int storeMembers[] const;
void setMemberInfo(std::string ID, std::string fName, std::string lName,
					int bPurchased, double amount);
void setMemberID(std::string);
void setName(std::string, std::string);

bool isMemberID(std::string);

int getBooksPurchased();
double getTotalAmountSpent();

void purchaseBook(double amount);

void resetbooksBoughtAndAmount();

void printMemberID();
void printName();

void printInfo();
	std::string memberID, firstName, lastName;
	int booksPurchased;
	double totalSpent;


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
	std::string title;std::string ISBN;std::string Publisher;
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
void memberType::setMemberInfo(std::string ID, std::string fName, std::string lName,
					int bPurchased, double amount)
{
	memberID=ID;
	firstName=fName;
	lastName=lName;
	totalSpent=amount;
	booksPurchased=bPurchased;
}
void memberType::setMemberID(std::string s){
	memberID=s;
}
void memberType::setName(std::string s, std::string t){
	firstName=s;
	lastName=t;
}
bool memberType::isMemberID(std::string x)const{
	if(x==memberID)
		return true;
	else
		return false;

}
int memberType::getBooksPurchased()const
{
	return booksPurchased;

}
double memberType::getTotalAmountSpent()const
{
	return totalSpent;

}
void memberType::purchaseBook(double amount)
{
	 totalSpent=+amount;


}
void memberType::resetbooksBoughtAndAmount()
{
	//if member hits book 11, they will reset to zero.
	if(booksPurchased==11){
		booksPurchased=0;
		totalSpent=0;
	}
}
void memberType::printMemberID()const{
	cout<<"member id: "<<memberID<<endl;

}
void memberType::printName()const{
	cout<<"name: "<<firstName<<lastName<<endl;
}
void memberType::printInfo()const{
	cout<<"member id: "<<memberID<<endl;
	cout<<"name: "<<firstName<<lastName<<endl;
	cout<<"number of books bought: "<<booksPurchased<<endl;
	cout<<"totalSpent:$ "<<totalSpent<<endl;

}
memberType::memberType()
{
}
memberType::~memberType()
{

}





