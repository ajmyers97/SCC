//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : CH8_EX11.exe                                      * 
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
//* 11/2/17       amyers15 000.000.000 Initial release of program       * 
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#include <iostream>
#include <string>
using namespace std;

int readNumbers(int[]);
int addNumbers(int[], int[], int[], int, int);
void display(int[], int);

int main(){
	cout<<"Allen Myers\t"<<"CH8_EX11\t"<<"CH8_EX11.exe"<<endl;
     int numOne[20]={0}, numTwo[20]={0}, sum[21]={0};
     int lenNum1, lenNum2, sumLen;
     cout<<"Enter a positive integer of at most 20 digits: ";
    	lenNum1 = readNumbers(numOne);
     cout<<"Enter a positive integer of at most 20 digits: ";
     lenNum2 = readNumbers(numTwo);
     cout<<endl<<endl;
     sumLen = addNumbers(numOne, numTwo, sum, lenNum1, lenNum2);


     if(sumLen<=20){
     cout<<endl<<endl<<"The sum of the numbers is: ";
          display(sum, sumLen);
     }
     else{
        cout<<"The sum of the numbers overflows, it has 21 digits."<<endl;
          display(sum, sumLen);
     }
     cout<<endl;
}
int readNumbers(int num[20]){
    string number;
     getline(cin, number);
     for (int i=0;i<(int)number.length();i++)
          num[i]=(int)number[number.length()-1-i]-48;
     return number.length();
}
int addNumbers(int a[20], int b[20], int sum[20], int lenA, int lenB){
     int carry=0,length, temp,i;
     if (lenA>lenB)
          length = lenA;
     else
          length = lenB;
     for(int i=0;i<length;i++){
          temp=a[i]+b[i]+carry;
          sum[i]=temp%10;
          carry=temp/10;
     }
     if(carry==0){
          return length;
     }
     else
          sum[i]=carry;
     return length+1;                 
}
void display(int a[20], int n){
     for(int i=n-1;i>-1;i--)
          cout<<a[i];  
}