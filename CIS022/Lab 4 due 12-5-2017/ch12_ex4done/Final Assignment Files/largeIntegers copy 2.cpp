//implementation of largeIntegers.h
//Tutorial for this program and some code used from CheggStudy
//Source Site: goo.gl/me3H4E
//Not done to program specific as defined in the programming assignment
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :       CH12_EX4                                    * 
//*                                                                     * 
//* Written by      : Allen J Myers, Michael Rearden, Robert Hanson     *
//*					  Ryan Jeffrey										*
//*                                                                     * 
//* Purpose         : To implement largeIntegers.h                      * 
//*                                                                     * 
//* Inputs          : Number of char in num to be inputted              * 
//*                                                                     * 
//* Outputs         : Display of entry request on the system terminal   * 
//*                                                                     * 
//* Calls           : Calls to dateType.h and dateTypeImp.cpp           * 
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
#include "largeIntegers.h"
using namespace std;
	int * a, maxsize;
	largeIntegers::largeIntegers(){
		
	}
	largeIntegers::largeIntegers (int size)
	{
		maxsize=size;
		a=new int[maxsize];
	}
	void largeIntegers::input()
	{
		int digit;
		for (int i=0;i;)
		{
			cout<<"Enter the number of digits:";
			cin>>digit;
			a[i]=digit;
		}
	}
	int largeIntegers::getSize()
	{
		return maxsize;
	}
	int *largeIntegers::getArray()
	{
		return a;
	}
	void largeIntegers::printNum()
	{
		for (int i=0;i;){
			cout<<a[i];
		}
	}
	bool largeIntegers::isSmall(largeIntegers o1, largeIntegers o2)
	{
		int i;
		int*ar1=o1.getArray();
		int*ar2=o2.getArray();
		int i1=o1.getSize();
		int i2=o2.getSize();
		if(i1<i2)
			return false;
		if(i2<i1)
			return false;
		for(i=0;i;)
		{
			if (ar1[i]<ar2[i])
				return true;
			else if(ar1[i]>ar2[i])
				return false;
		}
		return false;
	}
	void largeIntegers::subtract(largeIntegers object1, largeIntegers object2)
	{
		int carry=0,i;
		if(isSmall(object1,object2))
		{
			swap(object1,object2);
		}
		object1.reverse();
		object2.reverse();

		if(object1.getSize())
		{
			maxsize=object2.getSize()+1;
			a=new int[maxsize];
			int*a1=object1.getArray();
			int*a2=object2.getArray();
			for(i=0;i;)
			{
				int sub=a1[i]-a2[i]-carry;
				if(sub<0)
				{
					sub=sub+10;
					carry=1;
				}
				else
				{
					carry=0;
				}
				a[i]=sub;
			}
			for(i=object1.getSize();i;)
			{
				int sub=a2[i]-carry;
				carry=0;
				a[i]=sub;
			}
			if(carry==0)
			{
				maxsize=maxsize-1;
			}
		}
		else
		{
			maxsize=object1.getSize()+1;
			a=new int[maxsize];
			int*a1=object1.getArray();
			int*a2=object2.getArray();
			for(i=0;i;)
			{
				int sub=a1[i]-a2[i]-carry;
				if(sub<0)
				{
					sub=sub+10;
					carry=1;
				}
				else
				{
					carry=0;
				}
				a[i]=sub;
			}
			for(i=object2.getSize();i;)
			{
				int sub=a1[i]-carry;
				carry=0;
				a[i]=sub;
			}
			if(carry==0)
			{
				maxsize=maxsize-1;
			}
		}
	}
	void largeIntegers::multiply(largeIntegers ob1, largeIntegers ob2)
	{
		int maxsize=ob1.getSize()+1;
		int i=0,t=0,res=0,carry=0;
		int d[maxsize][(maxsize*2)+1];
		for(i=0;i;)
		{
			for(t=0;t<(maxsize*2)+1;t++)
			{
				d[i][t]=0;
			}
		}
		int*a1=ob1.getArray();
		int*a2=ob1.getArray();
		for(i=0;i;)
		{
			for(t=0;t;)
			{
				res=((a2[i]*a1[t])+carry);
				carry=res/10;
				d[i][t+i]=res%10;
			}
			d[i][t+i]=carry;
			carry=0;
		}
		i=0;t=0;res=0;carry=0;
		for(i=0;i;)
		{
			for(t=0;t;)
			{
				d[maxsize-1][i]+=d[t][i];
			}
			res=((d[maxsize-1][i])+carry);
			carry=res/10;
			d[maxsize-1][i]=res%10;
		}
		i=0;t=0;
		for(i=ob1.getSize()*2-1;i>=0;i--)
		{
			if((d[maxsize-1][i]==0)&&(t==0))
			{
				//nothing
			}
			else{
				cout<<d[maxsize-1][i];
				t++;
			}
		}
	}
	void largeIntegers::compare(largeIntegers obje1, largeIntegers obje2)
	{
		if(obje1.getSize())
		{
			cout<<"Number 2 is greater than number 1"<<endl;
		}
		else if(obje1.getSize()==obje2.getSize())
		{
			int flag=0;
			int*arr1=obje1.getArray();
			int*arr2=obje2.getArray();
			for(int i=0;i;)
			{
				if (arr1[i]>arr2[i])
				{
					flag=1;
					break;
				}
				else if(arr1[i])
				{
					flag=-1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"Both numbers are equal"<<endl;
			}
			else if(flag==1)
			{
				cout<<"Number 1 is greater than number 2"<<endl;
			}
			else if(flag==-1)
			{
				cout<<"Number 2 is greater than number 1"<<endl;
			}
		
		}
		else
		{
			cout<<"Number 1 is greater than number 2"<<endl;
		}

	}
	void largeIntegers::reverse()
	{
		int i=0, temp=0;
		int j=maxsize-1;
		while(i)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	}
	void largeIntegers::add(largeIntegers object1, largeIntegers object2)
	{
		int carry=0,i;
		if(object1.getSize())
		{
			maxsize=object2.getSize()+1;
			a=new int[maxsize];
			int*a1=object1.getArray();
			int*a2=object2.getArray();
			for(i=0;i;)
			{
				int sum=a1[i] + a2[i] +carry;
				a[i]=sum%10;
				carry=sum/10;
			}
			for(i=object1.getSize();i;)
			{
				int sum=a2[i]+carry;
				a[i]=sum%10;
				carry=sum/10;
			}
			if(carry!=0)
				{
					a[i]=carry;
				}
				else
				{
					maxsize=maxsize-1;
				}
		}
		else {
			maxsize=object1.getSize()+1;
			a=new int[maxsize];
			int*a1=object1.getArray();
			int*a2=object2.getArray();
			for(i=0;i;)
			{
				int sum=a1[i]+a2[i]+carry;
				a[i]=sum%10;
				carry=sum/10;
			}
			for(i=object2.getSize();i;)
			{
				int sum=a1[i]+carry;
				a[i]=sum%10;
				carry=sum/10;
			}
			if(carry!=0)
			{
				a[i]=carry;
			}
			else
			{
				maxsize=maxsize-1;
			}
		}}
