#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void E(char, string[], string);
void T(string[], string, int);
int main()
{
	string productions[]={"E->nT$", "T->*nT", "T->#"};
	char start_state='E';
	string input;
	cout<<"Enter the string\n";
	cin>>input;
	//input=input+"$";
	//cout<<input;

	E(start_state, productions, input);
}

void E(char s, string productions[], string input)
{
	static int j=0;
	int i=3;
	char lookhead=input[j++];
	if(lookhead==productions[0][i++] && j<=input.length())
	{
		T(productions, input, j);	
	}
	else
		cout<<"String Rejected: Try with different string\n";
	if(input[j]=='$')
		cout<<"String Accepted1\n";
}

void T(string productions[], string input, int loc)
{
	int i=3;
	char lookhead=input[loc++];
	
	if(lookhead==productions[1][i++] && loc<input.length())
	{
		if(input[loc++]==productions[1][i++])
		{
			lookhead=input[loc-1];
			T(productions, input, loc);
			if(input[loc]=='$')
				cout<<"String Accepted\n";
			else
				cout<<"String Rejected: Try with different string\n";
		}
		else
			cout<<"String Rejected:";
	}
	return;
}