#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define pb push_back

void recur(string[], char, int, map<char, vector<char > > &m, char);
int main()
{
int n;
cout<<"Enter the number of productions\n";
cin>>n;
cout<<"Enter the productions\n";
string productions[n];
for(int i=0;i<n;i++)
{
cin>>productions[i];
}

set<char> non_terminals;
map<char, vector<char> > m;
for(int i=0;i<n;i++)
{
non_terminals.insert(productions[i][0]);
}

set<char> :: iterator it;

for(it=non_terminals.begin();it!=non_terminals.end();it++)
{
//cout<<*it<<" ";
for(int i=0;i<n;i++)
{
if(*it==productions[i][0])
{
if(productions[i][3]<65 || productions[i][3]>90)
{
m[*it].pb(productions[i][3]);
}
else
{
char c=productions[i][3];
//cout<<c;
char c1=*it;
recur(productions, c, n, m, c1);
}
}
}
}

map<char, vector<char> > :: iterator it1;
for(it1=m.begin();it1!=m.end();it1++)
{
vector<char> v=m[it1->first];
set<char> se;
cout<<it1->first<<"\n";
for(int i=0;i<v.size();i++)
{
if(se.find(v[i])==se.end())
{
cout<<v[i]<<"  ";
se.insert(v[i]);
}
}
cout<<"\n";
}

}

void recur(string productions[], char c, int n, map<char, vector<char> > &m, char c1)
{
for(int i=0;i<n;i++)
{
if(productions[i][0]==c)
{
if(productions[i][3]<65 || productions[i][3]>90)
{
m[c1].pb(productions[i][3]);
}
else
{
c=productions[i][3];
recur(productions, c, n, m, c1);
}
}
}
}









