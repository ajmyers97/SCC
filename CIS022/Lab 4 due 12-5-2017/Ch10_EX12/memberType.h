//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :       CH10_Ex12                                   * 
//*                                                                     * 
//* Written by      : Allen J Myers, Michael Rearden, Robert Hanson,    * 
//*					  Ryan Jeffrey										*
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
#include <string>

class memberType{
private:
	std::string memberID, firstName, lastName;
	int booksPurchased;
	double totalSpent;

public:
//int storeMembers[] const;
void setMemberInfo(std::string ID, std::string fName, std::string lName,
					int bPurchased, double amount);
void setMemberID(std::string);
void setName(std::string, std::string);

bool isMemberID(std::string)const;

int getBooksPurchased()const;
double getTotalAmountSpent()const;

void purchaseBook(double amount);

void resetbooksBoughtAndAmount();

void printMemberID()const;
void printName()const;

void printInfo()const;

memberType();
~memberType();
};