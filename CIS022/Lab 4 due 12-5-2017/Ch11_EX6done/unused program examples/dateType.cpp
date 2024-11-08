//dateType.cpp-main program fro CH11_EX6
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :       CH11_EX6                                    * 
//*                                                                     * 
//* Written by      : Allen J Myers, Michael Rearden, Robert Hanson     * 
//*                                                                     * 
//* Purpose         : To test implementations of dateTypeImp.cpp        * 
//*                                                                     * 
//* Inputs          : No input calls from user                          * 
//*                                                                     * 
//* Outputs         : Display of entry request on the system terminal   * 
//*                                                                     * 
//* Calls           : Calls to dateType.h and dateTypeImp.cpp           * 
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
#include "dateType.h"
#include "dateType.cpp"
using namespace std;

int main(){
	cout<<"Allen Myers,Robert Hanson,Michael Rearden\t"<<"dateType\t"<<"dateType.exe"<<endl;
	dateType date1(3,15,2008);
	date1.print();
	date1.setDate(10,10,2010); 
	date1.print();
	date1.setMonth(12);    
	date1.setDay(12);    
	date1.setYear(2012);    
	date1.print();    
	cout << "Elapsed Days since 1/1/2012 = "<<numberOfDaysPassed()<<endl<<"Days remaining in 2012 = "<< numberOfDaysLeft()<<endl;
	date1.incrementDays(378); //add 378 days to the current date
	cout<<date1.getMonth()<<"/"<<date1.getDay()<<"/"<< date1.getYear()<<"/\n";
	cout<<"There are "<<getDaysInMonth()<< "days in this month\n"<<"and this year "<<isLeapYear() ? "is" : "is not"<<"a leap year.\n";    
	
	return 0;
}