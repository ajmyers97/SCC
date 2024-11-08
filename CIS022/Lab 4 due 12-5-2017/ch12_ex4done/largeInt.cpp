//Program that uses the class largeIntegers
#include <iostream>
#include <iomanip>
#include <string>
#include "largeIntegers.h"
using namespace std;
int main()
{
	int digit1[] = {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0};
	int digit2[] = { 2,3,4,5,6,7,8,9,0,1, 2,3,4,5,6,7,8,9,0,1, 2,3,4,5,6,7,8,9,0,1, 2,3,4,5,6,7,8,9,0,1 };
	largeIntegers object1(digit1,40,'+');
	largeIntegers object2(digit2,40,'+');
	largeIntegers temp;
//object1.getNum(cin);
//object2.getNum(cin);
cout << "object1: ";
object1.printNum(cout);
cout << endl;cout << "object2: ";
object2.printNum(cout);
cout << endl;
temp = object1.add(object2);
cout << "object1 + object2 = ";
temp.printNum(cout);
cout << endl;
temp = object1.subtract(object2);
cout << "object1 - object2 = ";
temp.printNum(cout);
cout << endl;
temp = object1.multiply(object2);
cout << "object1 * object2 = ";
temp.printNum(cout);
cout << endl;
system("Pause");
return 0;
}