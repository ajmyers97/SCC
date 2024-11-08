//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :   CH12_EX4.                                       * 
//*                                                                     * 
//* Written by      : Allen J Myers, Michael Rearden, Robert Hanson     * 
//*                                                                     * 
//* Purpose         : To test implementations of largeIntegers.cpp      * 
//*                                                                     * 
//* Inputs          : No input calls from user                          * 
//*                                                                     * 
//* Outputs         : Display of entry request on the system terminal   * 
//*                                                                     * 
//* Calls           : Calls to largeIntegers.h and largeIntegers.cpp    * 
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
#include "largeIntegers.h"
using namespace std;

int main(){
	cout<<"Allen Myers,Robert Hanson,Michael Rearden\t"<<"largeIntegers\t"<<"largeIntegers.exe"<<endl;    
	largeIntegers num1,num2;     
	largeIntegers temp;    
	num1.getNum(cin);    
	num2.getNum(cin);    
	cout << "num1: ";    
	num1.printNum(cout);    
	cout << endl;    
	cout << "num2: ";    
	num2.printNum(cout);    
	cout << endl;    
	temp =  num1.add(num2);    
	cout << "num1 + num2 = ";    
	temp.printNum(cout);    
	cout << endl;    
	temp =  num1.subtract(num2);    
	cout << "num1 - num2 = ";    
	temp.printNum(cout);    
	cout << endl;    
	temp =  num1.multiply(num2);    
	cout << "num1 * num2 = ";    
	temp.printNum(cout);    
	cout << endl;
	system("PAUSE");
	return 0;
}