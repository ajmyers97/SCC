#include <iostream>
#include "largeIntegers.h"
using namespace std;

int main()
{
	int n1, n2;
	cout<<"Enter the number of digits for num 1"<<endl;
	cin>>n1;
	largeIntegers obj1(n1);
	cout<<"Enter the first number:"<<endl;
	obj1.getNum();
	obj1.reverse();
	cout<<endl;
	cout<<"Enter the number of digits for num 2"<<endl;
	cin>>n2;
	largeIntegers obj2(n2);
	cout<<"Enter the second number"<<endl;
	obj2.getNum();
	obj2.reverse();
	cout<<endl;
	largeIntegers obj3;
	obj3.add(obj1,obj2);
	obj3.reverse();
	cout<<"The sum of the two numbers is: "<<endl;
	obj3.printNum();
	cout<<endl;
	obj1.reverse();
	obj2.reverse();
	obj3.subtract(obj1,obj2);
	obj3.reverse();
	cout<<"Difference of the two numbers is:"<<endl;
	obj3.printNum();
	cout<<endl;
	largeIntegers obj4;
	cout<<"Product of the two numbers:"<<endl;
	obj4.multiply(obj1,obj2);
	cout<<endl;
	largeIntegers obj5;
	obj5.compare(obj1,obj2);
	return 0;
}