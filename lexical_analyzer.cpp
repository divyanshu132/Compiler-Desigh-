// 	Treat comments as Reference...

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
using namespace std;

bool constant(char ch);
int main()
{
	char ch;
	// strings operators, delimiters and keywords can be extended.

	string operators="+-*/%=";
	string delimiter=",;)(}{]['<";

	char keywords[][20]={"if", "else", "while", "for", "int", "float",
						 "char", "main", "return", "void", "cout", 
						 "iostream", "include", "stdioh","using", "namespace", "printf", "std"};
	int keywords_size=sizeof(keywords)/sizeof(keywords[0]);

	char alphanumeric[20];int j=0;
	
	// read the file
	ifstream fin("sum.cpp");

	int helper_variable=0;  // it will help in cases like c=a+b where c,a,b will be printed
							// separately and not all together as cab.
	while(!fin.eof())
	{
		ch=fin.get(); // read char by char.

		//check for operators.
		for(int i=0;i<operators.length();i++)
		{
			if(ch==operators[i])
			{
				helper_variable=1;
				cout<<ch<<" is an operator\n";
				break;
			}
		}

		// check for delimiters.
		for(int i=0;i<delimiter.size();i++)
		{
			if(delimiter[i]==ch)
			{
				helper_variable=1;
				cout<<ch<<" is delimiter\n";
				break;
			}
		}
		
		//  isalnum will return true only if ch is alphanumeric.
		if(isalnum(ch))
		{
			int flag=1;
			// while we read integral number(constant) we print it directly without storing 
			//  it in alphanumeric array.
			while(constant(ch))
			{
				cout<<ch;
				ch=fin.get();
				flag=0;
			}
			if(flag==0)
				cout<<" is constant\n";
			
			alphanumeric[j]=ch;   // will have only characters
			j++;
		}
		else if((ch==' '||ch=='\n'||helper_variable==1) && (j!=0))
		{
			alphanumeric[j]='\0'; // append at the end of char array to convert it in string 
								  // so that strcmp can be used for comparison. 
			j=0;
			int helper=0;
				for(int i=0;i<keywords_size;i++)
				{
					if(strcmp(keywords[i], alphanumeric)==0)
					{
						helper=1;
						break;
					}
				}
				// check for keyword
				if(helper==1)
				{
					cout<<alphanumeric<<" is keyword\n";
					helper_variable=0;
				}
				// check for identifier
				else if(helper==0 && helper_variable==0)
					cout<<alphanumeric<<" is identifier\n";

				// print char by char if it is not a keyword and an operator or delimiter 
				// must be encountered in between the characters.
				else if(helper_variable==1 && helper==0)
				{
					int i=0;
					while(alphanumeric[i]!='\0')
					{
						cout<<alphanumeric[i]<<" is identifier\n";
						i++;
					}
					helper_variable=0;
					alphanumeric[0]='\0';
				}
		}
	}
}


bool constant(char ch)
{
	string constant="0123456789";
	for(int i=0;i<constant.length();i++)
	{
		if(constant[i]==ch)
			return true;
	}
	return false;
}