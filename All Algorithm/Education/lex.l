%{
	int integers = 0, numbers = 0, usernames = 0;
	int iii_numbers = 0, too_points = 0;
%}
DIGIT      [0-9]
NUMBER     [+-]?{DIGIT}+
DECIMAL    [+-]?({DIGIT}+[.]{DIGIT}+)|[.]({DIGIT}+)
USERNAME   [A-Za-z][A-Za-z0-9]*
END        [ ]|[\n]|[,]
%%
{NUMBER}[E]{DECIMAL} {
	iii_numbers++;
	printf("III Formed numbers: %s\n", yytext);
}
({NUMBER}[.]+{NUMBER})({NUMBER}[.]+{NUMBER})+ {
	too_points++;
	printf("Too Many Decimal Points: %s\n", yytext);
}
{USERNAME} {
	usernames++;
	printf("Valid Usernames: %s\n", yytext);
}
{DECIMAL}|({DECIMAL}[E]{NUMBER}) {
	numbers++;
	printf("Numers: %s\n", yytext);
}
[-]?{DIGIT}+ {
	integers++;
	printf("Integers: %s\n", yytext);
}
.|\n {}
%%
int yywrap() {}
int main()
{
	yyin=fopen("input.txt","r");
	yylex();
	puts("");
	printf("Number of integers:    = %d\n", integers);
	printf("Number of numbers:     = %d\n", numbers);
	printf("Number of usernames:   = %d\n", usernames);
	printf("Number of iii_numbers: = %d\n", iii_numbers);
	printf("Number of too_points:  = %d\n", too_points);
	return 0;
}

/*
III Formed numbers: 		12, -12, 0, 00, 120, 0125, -03214
Too Many Decimal Points: 	12.4, 12.36, 12.0, -12.0, -523.65, -53.0E10, 9.9E-12, 9.4E120
Valid Usernames: 			nayan biswas --nayan ads12b
Numers: 					10E10.5, -1E-12.56
Integers: 					12.23.45, 125...12412.23641.24

`flex lex.l && gcc lex.yy.c && ./a.out`
*/