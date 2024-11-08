//Module: CIS023_S2018_HW3 Allen Myers.cpp
//Program:		CIS023_S2018_HW3 Allen Myers.
//Author:		Allen Myers
//Date:			February 3rd, 2018
//Purpose:		Implementation File for StringConversionClass
//				Convert TCHAR to String
//				Convert string to TCHAR
//

#include "stdafx.h"
#include "StringConversionClass.h"


StringConversionClass::StringConversionClass()
{
}


StringConversionClass::~StringConversionClass()
{
}

TCHAR*StringConversionClass::ConvertTCHARtoString(TCHAR*sz1)
{

		string strReturn;					//resulting string
	
		string str1;				//work strings, converted from sz1, and sz2-local to this section
	
		size_t pRet;				//return value from mbstowcs_s()
	
	
									//converts TCHAR to string
		if (lstrlen(sz1) != 0)			//do nothing to an empty TCHAR
		{
			wstring temp(sz1);			//convert TCHAR to wString
			string str(temp.begin(), temp.end()); //convert wstring to string
			str1 = str;				//copy to local variable
	
		}
	
		strReturn = str1;		//display the results
	
		mbstowcs_s(					//convert string to TCHAR
			&pRet,						//return value
			szReturnString,					//destination TCHAR
			100,						//number of char TCHAR can take
			strReturn.c_str(),			//text of source string
			100							//max chars to copy(usually matches the TCHAR)
		);
	
		return szReturnString;	//returns new value
}
TCHAR*StringConversionClass::ConvertStringtoTCHAR(TCHAR*sz2)
{

		string strReturn;					//resulting string
	
//work string, converted from sz1, and sz2-local to this section
		string str2;
	
		size_t pRet;				//return value from mbstowcs_s()
	
	
									//converts TCHAR to string
		if (lstrlen(sz2) != 0)						//do nothing to an empty TCHAR
		{
			wstring temp(sz2);						//convert TCHAR to wString
			string str(temp.begin(), temp.end());   //convert wstring to string
			str2 = str;								//copy to local variable
	
		}
	
		strReturn = str2;		//display the results
	
		mbstowcs_s(					//convert string to TCHAR
			&pRet,						//return value
			szReturnTCHAR,					//destination TCHAR
			100,						//number of char TCHAR can take
			strReturn.c_str(),			//text of source string
			100							//max chars to copy(usually matches the TCHAR)
		);
	
		return szReturnTCHAR;	//returns new value
}
