#include "myFunctions.h"

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

void printBookData(bookType books[], int noOfBooks)
{
	for (int i = 0; i < noOfBooks; i++)
		books[i].printInfo();
}

void searchBookData(bookType books[], int bookCount)
{

}

void searchBookDataByISBN(bookType books[], int bookCount, string ISBN, int& loc)
{

}

void searchBookDataByTitle(bookType books[], int bookCount, string title, int& loc)
{

}

void updateCopiesInStock(bookType books[], int bookCount)
{

}

void showMenu()
{
	cout << "Welcome to Rock's Book Store" << endl;
	cout << "To make a selection enter the number and press enter" << endl;
	cout << "1: Print a list of books" << endl;
	cout << "2: Print a list of books and ISBN numbers" << endl;
	cout << "3: To see if a book in store" << endl;
	cout << "4: To update the number of copies of a book" << endl;
	cout << "5: To print members data" << endl;
	cout << "9: Exit the program." << endl;
}

void subMenu()
{
	cout << "Enter" << endl;
	cout << "1: To search the book by ISBN" << endl;
	cout << "2: To search the book by title" << endl;
}