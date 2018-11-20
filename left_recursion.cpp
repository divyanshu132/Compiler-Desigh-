#include<iostream>
#include<bits/stdc++.h>
#include<cstdlib>
#include<string>
using namespace std;

int main()
{
	int n;
	cout<<"Enter the number of productions\n";
	cin>>n;
	string productions[n];
	cout<<"Enter the productions in the form E->Ea\n";

	int left_recursive[n];
	int not_left_recursive[n];
	for(int i=0;i<n;i++)
	{
		cin>>productions[i];
	}
	int j1=0;int j2=0;
	cout<<"\n\n";
	
	for(int i=0;i<n;i++)
	{
		if(productions[i][0]==productions[i][3])
		{
			cout<<productions[i]<<" is left-recursive\n";
			left_recursive[j1]=i;
			j1++;
		}
		else if(productions[i][0]!=productions[i][3])
		{
			not_left_recursive[j2]=i;
			j2++;
		}
	}


	for(int i=0;i<j1;i++)
	{
		for(int j=0;j<j2;j++)
		{
			if(not_left_recursive[j]!=-1 && productions[left_recursive[i]][0]==productions[not_left_recursive[j]][0])
			{
				string s=productions[not_left_recursive[j]];
				cout<<s<<productions[not_left_recursive[j]][0]<<"'\n";
				not_left_recursive[j]=-1;
			}
		}
	}

	for(int i=0;i<j2;i++)
	{
		if(not_left_recursive[i]!=-1)
		{
			cout<<productions[not_left_recursive[i]]<<"\n";
		}
	}
	set<char> s;
	set<char> :: iterator it;
	for(int i=0;i<j1;i++)
	{
		cout<<productions[left_recursive[i]][0]<<"'";
		s.insert(productions[left_recursive[i]][0]);
		for(int j=0;j<productions[left_recursive[i]].length();j++)
		{
			if(j!=3 && j!=0)
			{
				cout<<productions[left_recursive[i]][j];
			}
		}
		cout<<productions[left_recursive[i]][0]<<"'\n";
	}
	for(it=s.begin();it!=s.end();it++)
		cout<<*it<<"'->"<<"*"<<"\n";
}
