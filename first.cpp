#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define pb push_back

void recur(string[], char, int, map<char, vector<char > > &m, char);
void follow(string[], char, int, map<char, vector<char > > &m1, map<char, vector<char > > &m);
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
/*for(it1=m.begin();it1!=m.end();it1++)
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
}*/




map<char, vector<char> > m1;
m1['E'].pb('$');
for(it=non_terminals.begin();it!=non_terminals.end();it++)
{
char c=*it;
cout<<c<<"\n";
follow(productions, c, n, m1, m);
}

cout<<"\n\n\n\n";
for(it1=m1.begin();it1!=m1.end();it1++)
{
cout<<it1->first<<"\n";
vector<char> v=m1[it1->first];
for(int i=0;i<v.size();i++)
{
cout<<v[i]<<"  ";
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



void follow(string productions[], char c, int n, map<char, vector<char> > &m1, map<char, vector<char> > &m)
{
for(int i=0;i<n;i++)
{
for(int j=3;j<productions[i].length();j++)
{
cout<<productions[i][j]<<" ";
if((int)productions[i][j]==(int)c)
{
cout<<"yo ";
if(j+1<productions[i].length() && (productions[i][j+1]<65 || productions[i][j+1]>90))
{
cout<<"HAa";
m1[c].pb(productions[i][j+1]);
}
else if(j+1==productions[i].length())
{
c=productions[i][0];
follow(productions, c, n, m1, m);
}
else if(j+1<productions[i].length() && (productions[i][j+1]>65 || productions[i][j+1]<90))
{
char c1=productions[i][j+1];
vector<char> v=m[c1];
for(int l=0;l<v.size();l++)
{
m1[c].pb(v[l]);
}
}
}
}
}
}










