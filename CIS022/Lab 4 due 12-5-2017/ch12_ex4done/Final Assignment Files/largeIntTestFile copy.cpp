#include <iostream>
#include <iomanip>
#include "largeIntegers.h"
using namespace std;

int main(){    
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