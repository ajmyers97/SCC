#include "BookType.h"

void getBookData(bookType books[], int& noOfBooks);
void printBookData(bookType books[], int noOfBooks);
void searchBookData(bookType books[], int bookCount);
void searchBookDataByISBN(bookType books[], int bookCount, string ISBN, int& loc);
void searchBookDataByTitle(bookType books[], int bookCount, string title, int& loc);
void updateCopiesInStock(bookType books[], int bookCount);
void showMenu();
void subMenu();
void header();