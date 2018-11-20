//		Write a program to check wheather a string is accepted by a grammar or not.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	// Grammar: S->aAb and A->aAb|e(epsilon).
	// Accepted strings are: a^n+b^n(n>=1);
	cout<<"Grammar is: S->aAb and A->aAb\n";
	char start='S';
	string terminals="ab";
	string productions[][10]={"aAb", "e"};

	cout<<"Enter the string to be verified\n";
	string test;
	cin>>test;
		int helper=0;int count_a=0;int count_b=0;int flag=0;
		for(int i=0;i<test.length();i++)
		{
			if(test[i]=='a' && helper==0)
				count_a++;
			if(test[i]=='b')
			{
				helper=1;
				count_b++;
			}
			if(helper==1 && test[i]=='a')
			{
				cout<<"Not Accepted\n";
				flag=1;
				break;
			}
		}
		if(flag==0 && count_b==count_a && count_a!=0)
			cout<<"Accepted\n";
		else
			cout<<"Not Accepted\n";
}