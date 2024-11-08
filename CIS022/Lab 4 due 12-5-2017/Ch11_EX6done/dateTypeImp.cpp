//dateTypeImp.cpp-implementation file for CH11_EX6
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :       CH11_EX6                                    * 
//*                                                                     * 
//* Written by      : Allen J Myers, Michael Rearden, Robert Hanson     *
//*					  Ryan Jeffrey										*
//*                                                                     * 
//* Purpose         : To implement dateType.h                           * 
//*                                                                     * 
//* Inputs          : No input calls from user                          * 
//*                                                                     * 
//* Outputs         : Display of entry request on the system terminal   * 
//*                                                                     * 
//* Calls           : Calls to dateType.h                               * 
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
#include "dateType.h"
using namespace std;

void dateType::setDate(int month, int day, int year)
{
	if(1 <= month && month <= 12) //make sure value of dMonth is valid
		dMonth = month;
	else
		dMonth = 1;

	if(year > 0)//make sure value of dYear is valid
		dYear = year;
	else
		dYear = 1;

	if(dMonth <= 7) //Months in range Jan-July: Odd numbered months have 31 days, even months have 30
	{
		if(dMonth % 2 == 1 && (1 <= day && day <= 31)) //make sure dDay is valid
			dDay = day;
		else if((dMonth % 2 == 0 && dMonth != 2) && (1 <= day && day <= 30))
			dDay = day;
		else if((dMonth == 2 && isLeapYear()) && (1 <= day && day <= 29)) //During leap year, Feb. has 29 days
			dDay = day;
		else if((dMonth == 2 && !isLeapYear()) && (1 <= day && day <=28)) //During normal year, Feb. has 28 days
			dDay = day;
		else
			dDay = 1;
	}
	else //Months in range Aug.-December: Odd numbered months have 30 days, even months have 31 days
	{
		if(dMonth % 2 == 1 && (1 <= day && day <= 30))
			dDay = day;
		else if(dMonth % 2 == 0 && (1 <= day && day <= 31))
			dDay = day;
		else
			dDay = 1;
	}

}

void dateType::setMonth(int month)
{
	if(1 <= month && month <= 12) //make sure dMonth is valid
		dMonth = month;
	else
		dMonth = 1;
}

void dateType::setDay(int day)
{
	if(dMonth <= 7) //months in range Jan-July: Odd numbered months have 31 days, even months have 30
	{
		if(dMonth % 2 == 1 && (1 <= day && day <= 31))
			dDay = day;
		else if((dMonth % 2 == 0 && dMonth != 2) && (1 <= day && day <= 30))
			dDay = day;
		else if((dMonth == 2 && isLeapYear()) && (1 <= day && day <= 29)) //During leap year, Feb. has 29 days
			dDay = day;
		else if((dMonth == 2 && !isLeapYear()) && (1 <= day && day <=28)) //During normal year, Feb. has 28 days
			dDay = day;
		else
			dDay = 1;
	}
	else //months in range Aug-December: Odd numbered months have 30 days, even months have 31
	{
		if(dMonth % 2 == 1 && (1 <= day && day <= 30))
			dDay = day;
		else if(dMonth % 2 == 0 && (1 <= day && day <= 31))
			dDay = day;
		else
			dDay = 1;
	}
}

void dateType::setYear(int year)
{
	if(year > 0) //make sure year is valid
		dYear = year;
	else
		dYear = 1;

}

void dateType::incrementDays(int dayAmount)
{
	//increments number of days depending on user input
	cin>>dayAmount;
	cout<<endl;
    while ((dayAmount + dDay) > dateType::getDaysInMonth())
    {
        dayAmount -= dateType::getDaysInMonth();
        if (dMonth == 12)
        {
            dMonth = 0;
            dYear++;
        }   
        dMonth++;
    }
    dDay += dayAmount;
}

int dateType::getDaysInMonth()
{
	if(dMonth <= 7) //find days of months in range Jan.-July
	{
		switch(dMonth % 2)
		{
		case 0:
			if(dMonth == 2 && isLeapYear())
				return 29;
			else if(dMonth == 2 && !isLeapYear())
				return 28;
			else
				return 30;
		case 1:
				return 31;
		}//end switch
	} //end if
	else //find months in range August-December
	{
		switch(dMonth % 2)
		{
		case 0:
			return 31;
		case 1:
			return 30;
		} //end switch
	} //end else
	return 0;
}

int dateType::numberOfDaysPassed()
{
	switch(dMonth)
	{
	case 1:
		return dDay;
	case 2:
		return (31 + dDay);
	case 3:
		if(dateType::isLeapYear())
			return (60 + dDay);
		else
			return (59 + dDay);
	case 4:
		if(isLeapYear())
			return (91 + dDay);
		else
			return (90 + dDay);
	case 5:
		if(isLeapYear())
			return (121 + dDay);
		else
			return (120 + dDay);
	case 6:
		if(isLeapYear())
			return (152 + dDay);
		else
			return (151 + dDay);
	case 7:
		if(isLeapYear())
			return (182 + dDay);
		else
			return (181 + dDay);
	case 8:
		if(isLeapYear())
			return (213 + dDay);
		else
			return (212 + dDay);
	case 9:
		if(isLeapYear())
			return (244 + dDay);
		else
			return (243 + dDay);
	case 10:
		if(isLeapYear())
			return (274 + dDay);
		else
			return (273 + dDay);
	case 11:
		if(isLeapYear())
			return (305 + dDay);
		else
			return (304 + dDay);
	case 12:
		if(isLeapYear())
			return (335 + dDay);
		else
			return (334 + dDay);
	}
	return 0;
}

int dateType::numberOfDaysLeft()
{
	if(isLeapYear())
		return (366 - numberOfDaysPassed());
	else
		return (365 - numberOfDaysPassed());
}

int dateType::getDay() const
{
	return dDay;
}

int dateType::getMonth() const
{
	return dMonth;
}

int dateType::getYear() const
{
	return dYear;
}

bool dateType::isLeapYear()
{
	return(dYear % 4 == 0 && (dYear % 100 != 0 || dYear % 400 == 0));
}

void dateType::print() const
{
	cout << dMonth << "-" << dDay << "-" << dYear << endl;
}

dateType::dateType(int month, int day, int year) //default constructor. Same body as setDate function
{
	if(1 <= month && month <= 12)
		dMonth = month;
	else
		dMonth = 1;

	if(year > 0)
		dYear = year;
	else
		dYear = 1;

	if(dMonth <= 7)
	{
		if(dMonth % 2 == 1 && (1 <= day && day <= 31))
			dDay = day;
		else if((dMonth % 2 == 0 && dMonth != 2) && (1 <= day && day <= 30))
			dDay = day;
		else if((dMonth == 2 && isLeapYear()) && (1 <= day && day <= 29))
			dDay = day;
		else if((dMonth == 2 && !isLeapYear()) && (1 <= day && day <=28))
			dDay = day;
		else
			dDay = 1;
	}
	else 
	{
		if(dMonth % 2 == 1 && (1 <= day && day <= 30))
			dDay = day;
		else if(dMonth % 2 == 0 && (1 <= day && day <= 31))
			dDay = day;
		else
			dDay = 1;
	}
}