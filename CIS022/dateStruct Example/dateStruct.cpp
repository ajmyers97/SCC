//Date Structure

#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

struct dateStruct 
{
	int dateDay;
	int dateMonth;
	int dateYear;
	int dateDayOfYear;
	string dateMonthname;
};

bool ReadDate(dateStruct&);
bool WriteDate(dateStruct&);
int ConvertToInt(string);
string ConvertToMonthName(int);
int ConvertToDayOfYear(dateStruct&);

int main()
{
	dateStruct MyBirthDate;
	dateStruct YourBirthdate;

	cout << "Enter Your birthdate\n";
	while (!ReadDate(YourBirthdate))
	{
		cout << "Input error Try again.\n";
	};

	MyBirthDate = YourBirthdate;

	if (!WriteDate(MyBirthDate))
	{
		cout << "System error, Terminate!";
		return 0;
	}


	cout << "\nFinished Processing\nPress any key to continue.";
	
	system("pause");
	//YourBirthdate.dateDay = 01;
	//YourBirthdate.dateMonth = 01;
	//YourBirthdate.dateYear = 0000;
	//YourBirthdate.dateMonthname = ConvertToMonthName(YourBirthdate.dateMonth);
	//YourBirthdate.dateDayOfYear = ConvertToDayOfYear(YourBirthdate);

}

bool ReadDate(dateStruct& brthDate)
{
	int inData = 0;
	string inputData;
	cout << "Enter the Birth year (yyyy) :";
	cin >> inputData;
	if (inputData.length() != 4)
	{
		cout << "You entered an incorrect Year.\n"
			<< " Terminating program";
		return false;
	}
	brthDate.dateYear = ConvertToInt(inputData);

	cout << "\nEnter the Birth month (mm) :";
	cin >> inputData;
	if (inputData.length() != 2)
	{
		cout << "You entered an incorrect Month.\n"
			<< " Terminating program\n";
		return false;
	}
	brthDate.dateMonth = ConvertToInt(inputData);

	if (brthDate.dateMonth > 12)
	{
		cout << "You entered an incorrect Month.\n"
			<< " Terminating program";
		return false;
	}
	brthDate.dateMonthname = ConvertToMonthName(brthDate.dateMonth);

	cout << "\nEnter the Birth day (dd) :";
	cin >> inputData;
	if (inputData.length() != 2)
	{
		cout << "You entered an incorrect Year.\n"
			<< " Terminating program";
		return false;
	}
	brthDate.dateDay = ConvertToInt(inputData);

	brthDate.dateDayOfYear = ConvertToDayOfYear(brthDate);
	return true;
}

bool WriteDate(dateStruct& brthDate)
{
	cout << "Your Birth Day is -------------------- " << brthDate.dateDay;
	cout << "\nYour Birth Month is ---------------- " << brthDate.dateMonth;
	cout << "\nYour Birth Year is ----------------- " << brthDate.dateYear;
	cout << "\nDays from beginning of birth year is " << brthDate.dateDayOfYear;
	cout << "\nYour Birth month name is ----------- " << brthDate.dateMonthname;
	return true;
}

int ConvertToInt(string inStr)
{
	int inData = 0;

	for (int i = 0; i < static_cast<int>(inStr.length()); ++i)
	{
		if (inStr[i] < '0' || inStr[i] > '9')
		{
			cout << "Year is not numeric.\n";
			return false;
		}
		inData *= 10;
		switch (inStr[i])
		{
		case '0':
			break;
		case '1':
			inData += 1;
			break;
		case '2':
			inData += 2;
			break;
		case '3':
			inData += 3;
			break;
		case '4':
			inData += 4;
			break;
		case '5':
			inData += 5;
			break;
		case '6':
			inData += 6;
			break;
		case '7':
			inData += 7;
			break;
		case '8':
			inData += 8;
			break;
		case '9':
			inData += 9;
			break;
		}
	}
    return inData;
}

string ConvertToMonthName(int month)
{
	switch (month)
	{
	case 01:
		return "January";
		break;
	case 02 :
		return "February";
		break;
	case 03 :
		return "March";
		break;
	case 04 :
		return "April";
		break;
	case 05 :
		return "May";
		break;
	case 06 :
		return "June";
		break;
	case 07 :
		return "July";
		break;
	case 8 :
		return "August";
		break;
	case 9 :
		return "September";
		break;
	case 10 :
		return "October";
		break;
	case 11 :
		return "November";
		break;
	case 12 :
		return "December";
		break;
	}
	return "";
}

int ConvertToDayOfYear(dateStruct& bthdate)
{
	int daysFromBegOfYr = 0;
	
	switch (bthdate.dateMonth)
	{
	case 1:
		break;
	case 2:
		daysFromBegOfYr += 31;
		break;
	case 3:
		daysFromBegOfYr += 31 + 31;
		break;
	case 4:
		daysFromBegOfYr += 31 + 31 + 30;
		break;
	case 5:
		daysFromBegOfYr += 31 + 31 + 30 + 31;
		break;
	case 6:
		daysFromBegOfYr += 31 + 31 + 30 + 31 + 30;
		break;
	case 7:
		daysFromBegOfYr += 31 + 31 + 30 + 31 + 30 + 31;
		break;
	case 8:
		daysFromBegOfYr += 31 + 31 + 30 + 31 + 30 + 31 + 31;
		break;
	case 9:
		daysFromBegOfYr += 31 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
		break;
	case 10:
		daysFromBegOfYr += 31 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
		break;
	case 11:
		daysFromBegOfYr += 31 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
		break;
	case 12:
		daysFromBegOfYr += 31 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31;
		break;
	}

	daysFromBegOfYr += bthdate.dateDay;
	
	return daysFromBegOfYr;
}