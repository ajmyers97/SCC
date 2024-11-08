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
class memberType{
const int MAX_MEM   =   500
;     // Maximum members

private:
	string ID, string fName, string lName;
	int bPurchased;
	double amount;

public:
void setMemberInfo(string ID, string fName, string lName,
					int bPurchased, double amount);
void setMemberID(string);
void setName(string, string);

bool isMemberID(string)const;

int getBooksPurchased()const;
double getTotalAmountSpent()const;

void purchaseBook(double amount);

void resetBookBoughtAndAmount();

void printMemeberID()const;
void printName()const;

void printInfo()const;

memberType();
}