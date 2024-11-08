
//
#pragma once
class MetricConvert :
	public string
{
public:
	MetricConvert();
	~MetricConvert();

	MetricConvert(TCHAR*);		//overload, stores user input
	TCHAR*GetCM();				//converts ststring in base class to centimeters
	TCHAR*GetIN();				//converts string in base class to inches

private:
	TCHAR szReturn[100];		//return value
};

