//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : CH6_EX19                                           * 
//*                                                                     * 
//* Written by      : Allen J Myers                                     * 
//*                                                                     * 
//* Purpose         : To cause a message to display on the system       * 
//*                   console. This program will be executed from the   * 
//*                   terminal at the computer room door by personnel   * 
//*                   needing service.                                  * 
//*                                                                     * 
//* Inputs          : User enters HELLO on the terminal command line    * 
//*                                                                     * 
//* Outputs         : Display of entry request on the system terminal   * 
//*                                                                     * 
//* Calls           : No internal or external calls                     * 
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
//* 10/03/17      amyers15 000.000.000 Initial release of program       * 
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#include <iostream>
using namespace std;

bool leapYear(int);
int dayNumber(int, int, int);

int main ()
{
	int month,day,year,leap,number;
	cout << "Enter date in the form (mm/dd/yyyy): ";
	char slash_dummy;
	std::cin >> month >> slash_dummy >> day >> slash_dummy >> year;
	leap = leapYear(year);
	numberOfYear = dayNumber(month, day, leap);

	cout << "This is day number " << numberOfYear <<" of the year "<<year<< endl;
	if (leap == 1)
	cout << "because it is a leap year." << endl;
	if (leap == 0)
	cout <<endl;

	system ("pause");

	return 0;
}
bool leapYear(int year)
{
	if (year % 400 == 0)
	{ 
		return true;
	}
	if (year % 100 == 0)
	{
		return false;
	}
	if (year % 4 == 0)
	{
		return true;
	}
	if (year % 4 !=0)
	{
		return false;
	}
}

int dayNumber(int month, int day, int leap)
{
	if (month == 1)
	{
		return day;
	}
	if (month == 2)
	{
		return 31 + day;
	}
	if (month == 3)
	{
		return 59 + day + leap;
	}
	if (month == 4)
	{
		return 90 + day + leap;
	}
	if (month == 5)
	{
		return 120 + day + leap;
	}
	if (month == 6)
	{
		return 151 + day + leap;
	}
	if (month == 7)
	{
		return 181 + day + leap;
	}
	if (month == 8)
	{
		return 212 + day + leap;
	}
	if (month == 9)
	{
		return 243 + day + leap;
	}
	if (month == 10)
	{
		return 273 + day + leap;
	}
	if (month == 11)
	{
		return 304 + day + leap;
	}
	if (month == 12)
	{
		return 334 + day + leap;
	}
}
