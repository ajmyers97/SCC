//implementation of memberType.h
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :       CH10_Ex12                                   * 
//*                                                                     * 
//* Written by      : Allen J Myers, Michael Rearden, Robert Hanson     *
//*					  Ryan Jeffrey										*
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
#include <string>
#include "memberType.h"
using namespace std;

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
	return totalSpent+amount;


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