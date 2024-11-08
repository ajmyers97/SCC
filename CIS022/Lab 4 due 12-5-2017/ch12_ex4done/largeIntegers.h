//largeIntegers.h
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :   CH12_EX4.                                       * 
//*                                                                     * 
//* Written by      : Allen J Myers, Michael Rearden, Robert Hanson     *
//*					  Ryan Jeffrey										*
//*                                                                     * 
//* Purpose         : To test implementations of largeIntegers.cpp      * 
//*                                                                     * 
//* Inputs          : No input calls from user                          * 
//*                                                                     * 
//* Outputs         : Display of entry request on the system terminal   * 
//*                                                                     * 
//* Calls           : Implementation of largeIntegers.h                 * 
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
#include <string>
using namespace std;
class largeIntegers{
	public:
		void setNum(int list[], int length);     
		void printNum(ostream&);    
		void getNum(istream&);   
		void copyNum(const largeIntegers& right);    
		bool equal(const largeIntegers& right) const;    
		bool notEqual(const largeIntegers& right) const;    
		bool greaterThan(const largeIntegers& right) const;    
		bool lessThan(const largeIntegers& right) const;    
		bool lessOrEqualTo(const largeIntegers& right) const;    
		bool greaterOrEqualTo(const largeIntegers& right) const;    
		largeIntegers add(const largeIntegers& num);    
		largeIntegers subtract(const largeIntegers& num);    
		largeIntegers multiply(const largeIntegers& num);    
		largeIntegers();     
		largeIntegers(int list[], int length = 0, char numSign = '+');
	private:
		long long int number;

};
