%{

%}
	
%%
[\t]+

[+|-|*|%|/|=] {printf("\n%s is an operator\n", yytext);}		

[,|;|)|(|{|}|]|[|'|<|\|>]	{printf("\n%s is a delimiter", yytext);}

[if|else|while|for|printf|scanf|cout|cin|namespace|using|"#include"|int|main|void|return|float|char|stdio.h]+ {printf("\n%s is keyword\n", yytext);}

[0-9] {printf("\n%s is constant\n", yytext);}

[a-zA-z] {printf("\n%s is identifier\n", yytext);}
%%

int yywrap(){}

int main()
{
	FILE *fin;
	fin=fopen("sum.c", "r");
	yyin=fin;
	yylex();
}