//implementation of memberType.h
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :       CH10_Ex12                                   * 
//*                                                                     * 
//* Written by      : Allen J Myers, Michael Rearden, Robert Hanson     * 
//*                                                                     * 
//* Purpose         : To implement the fucntions of memberType.h        * 
//*                                                                     * 
//* Inputs          : No input calls from user                          * 
//*                                                                     * 
//* Outputs         : Display of entry request on the system terminal   * 
//*                                                                     * 
//* Calls           : Calls to memberType.h                             * 
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

void memberType::setMemberInfo(string ID, string fName, string lName,
					int bPurchased, double amount)
{
	memberID=ID;
	firstName=fName;
	lastName=lName;
	totalSpent=amount;
	booksPurchased=bPurchased
}
void memberType::setMemberID(string s){
	memberID=s;
}
void memberType::setName(string s, string t){
	firstName=s;
	lastName=t;
}
bool memberType::isMemberID(string x)const{
	if(x=memberID)
		return true;
	else
		return false;

}
int memberType::getBooksPurchased(string& s)const
{
	return booksPurchased;

}
double memberType::getTotalAmountSpent(string& s)const
{
	return totalSpent;

}
void memberType::purchaseBook(double amount)
{
	//needs to access and add the price of the book from file
	//to get a total and store it back to member info.

}
void memberType::resetBookBoughtAndAmount()
{
	//if member hits book 11, they will reset to zero.
	if(booksPurchased=11){
		booksPurchased=0;
		totalSpent=0;
}
}
void memberType::printMemberID()const{
	cout<<"member id: "<<memberID<<endl

}
void memberType::printName()const{
	cout<<"name: "<<firstName<<lastName<<endl;
}
void memberType::printInfo()const{
	cout<<"member id: "<<memberID<<endl
	cout<<"name: "<<firstName<<lastName<<endl;
	cout<<"number of books bought: "<<booksPurchased<<endl;
	cout<<"totalSpent:$ "<<totalSpent<<endl;

}
memberType::memberType()
{
	
}
memberType::memberType((string ID, string fName, string lName, int bPurchased, double amount))
{
setMemberInfo(ID,fName,lName,bPurchased,amount);
}
memberType::~memberType()
{

}