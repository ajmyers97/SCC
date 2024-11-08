//dateType.h
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :       CH11_EX6                                    * 
//*                                                                     * 
//* Written by      : Allen J Myers, Michael Rearden, Robert Hanson     * 
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
class dateType
{
public:
	void setDate(int month, int day, int year); 
	//set member variables dMonth, dDay, and dYear
	void setMonth(int month);
	//set member variable dMonth
	void setDay(int day); 
	//set member variable dDay
	void setYear(int year); 
	//set member variable dYear'
	void printDate() const;
	//print the date in the format: dMonth-dDay-dYear
	int numberOfDaysPassed() const;
	//return number of days passed in the year
	int numberOfDaysLeft() const;
	//return number of days remaining in the year
	void incrementDays(int nDays);
	//change date to new date
	int getDaysInMonth() const;
	//return number of days in dMonth
	int getDay() const;
	//return dDay
	int getMonth() const;
	//return dMonth
	int getYear() const;
	//return dYear
	bool isLeapYear() const;
	//check if dYear is a leap year
	dateType(int = 1, int = 1, int = 1900);
	//default variable
private:
	int dMonth, dDay, dYear;
};