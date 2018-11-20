//		Write a program to check wheather a String is accepted by a grammar or not.


// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
import java.util.*;
import java.io.*;
public class grammar
{
	// Grammar: S->aAb and A->aAb|e(epsilon).
	// Accepted strings are: a^n+b^n(n>=1);
	public static void main(String[] args)
	{
		//cout<<"Grammar is: S->aAb and A->aAb\n";
		System.out.println("Grammar is: S->aAb and A->aAb");
		char start='S';
		String terminals="ab";

		String[] productions={"aAb", "e"};
		//String productions[][10]={"aAb", "e"};

		//cout<<"Enter the String to be verified\n";
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the String to be verified");

		String test=sc.next();
		//cin>>test;
		int helper=0;int count_a=0;int count_b=0;int flag=0;
		for(int i=0;i<test.length();i++)
		{
			if(test.charAt(i)=='a' && helper==0)
				count_a++;
			if(test.charAt(i)=='b')
			{
				helper=1;
				count_b++;
			}
			if(helper==1 && test.charAt(i)=='a')
			{
				//cout<<"Not Accepted\n";
				System.out.println("Not Accepted");
				flag=1;
				break;
			}

		}
		if(flag==0 && count_b==count_a && count_a!=0)
			System.out.println("Accepted");
			//cout<<"Accepted\n";
		else
			System.out.println("Not Accepted");
			//cout<<"Not Accepted\n";
	}	
}