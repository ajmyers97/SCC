#include <iostream>

using namespace std;

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
	//set member variable dYear

	void calculateNewDate(int dayAmount);
	//calculate new date by adding a fixed amount of days to the date

	int getDaysInMonth() const;
	//return number of days in dMonth

	int getDaysPassed() const;
	//return number of days passed in the year

	int getDaysRemaining() const;
	//return number of days remaining in the year

	int getDay() const;
	//return dDay

	int getMonth() const;
	//return dMonth

	int getYear() const;
	//return dYear

	bool isLeapYear() const;
	//check if dYear is a leap year

	void printDate() const;
	//print the date in the format: dMonth-dDay-dYear

	dateType(int = 1, int = 1, int = 1900);
	//default constructor
private:
	int dMonth;
	int dDay;
	int dYear;
};

int main()
{	
	//Tested and verified all the functions, except calculateNewDate
	dateType myDate(12, 31, 2008);

	myDate.printDate();

	cout << "Total days passed in year is " << myDate.getDaysPassed() << endl;
	cout << "Total days remaining in year is " << myDate.getDaysRemaining() << endl;

	myDate.printDate();

	return 0;
}

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

void dateType::calculateNewDate(int dayAmount)
{
	//stumped with this function
}

int dateType::getDaysInMonth() const
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

}

int dateType::getDaysPassed() const
{
	switch(dMonth)
	{
	case 1:
		return dDay;
	case 2:
		return (31 + dDay);
	case 3:
		if(isLeapYear())
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
}

int dateType::getDaysRemaining() const
{
	if(isLeapYear())
		return (366 - getDaysPassed());
	else
		return (365 - getDaysPassed());
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

bool dateType::isLeapYear() const
{
	return(dYear % 4 == 0 && (dYear % 100 != 0 || dYear % 400 == 0));
}

void dateType::printDate() const
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