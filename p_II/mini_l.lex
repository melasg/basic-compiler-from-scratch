%{
#include <iostream>
#include <cstdlib>
using namespace std;
        int num_lines = 1, num_column = 1;
%}
%option noyywrap
%option nounput
%%
[0-9]+     {yylval.exp = new Num(atoi(yytext)); return NUM;}
[a-zA-Z0-9_]+ {yylval.id = new Id(yytext); return ID;}
function        printf("FUNCTION\n"); num_column += yyleng;
beginparams     printf("BEGIN_PARAMS\n"); num_column += yyleng;
endparams       printf("END_PARAMS\n"); num_column += yyleng;
beginlocals     printf("BEGIN_LOCALS\n"); num_column += yyleng;
endlocals       printf("END_LOCALS\n"); num_column += yyleng;
beginbody       printf("BEGIN_BODY\n"); num_column += yyleng;
endbody         printf("END_BODY\n"); num_column += yyleng;
integer         printf("INTEGER\n"); num_column += yyleng;
array           printf("ARRAY\n"); num_column += yyleng;
of              printf("OF\n"); num_column += yyleng;
then            printf("THEN\n"); num_column += yyleng;
endif           printf("ENDIF\n"); num_column += yyleng;
if         {return IF;}
ifelse     {return IFELSE;}
while      {return WHILE;}
read       {return READ;}
write      {return WRITE;}
do              printf("DO\n"); num_column += yyleng;
for             printf("FOR\n"); num_column += yyleng;
beginloop       printf("BEGINLOOP\n"); num_column += yyleng;
endloop         printf("ENDLOOP\n"); num_column += yyleng;
continue        printf("CONTINUE\n"); num_column += yyleng;
and|or     {yylval.op = (yytext[0] == 'a' ? AND : OR); return BOP;}
not        {yylval.op = NOT; return NOTTOK;}
true|false {yylval.exp = new BoolExp(yytext[0] == 't'); return BOOL;}
{ID}            printf("IDENT %s\n", yytext); num_column += yyleng; //{yyval=install_id(); return ID;}
{CHAR}          printf("IDENT %s\n", yytext); num_column += yyleng;
[><=]|([><!]=) {yylval.op = getCompOp(yytext); return COMP;}
":="       {return ASN;}
[+-]       {yylval.op = (yytext[0] == '+' ? ADD : SUB); return OPA;}
[*/]       {yylval.op = (yytext[0] == '*' ? MUL : DIV); return OPM;}
"%"             printf("MOD\n"); num_column += yyleng;
"<"             printf("LT\n"); num_column += yyleng;
">"             printf("GT\n"); num_column += yyleng;
";"        {return STOP;}
":"             printf("COLON\n"); num_column += yyleng;
","             printf("COMMA\n"); num_column += yyleng;
"("        {return LP;}
")"        {return RP;}
"["             printf("L_SQUARE_BRACKET\n"); num_column += yyleng;
"]"             printf("R_SQUARE_BRACKET\n"); num_column += yyleng;

<<EOF>>         { return 0; }
[ \t\n]+ { }
"#".*    { }
.        { scanerror(); return -1; }

%%
int main( int argc, char **argv) {
++argv, --argc;  /* skip over program name */
if ( argc > 0 )
        yyin = fopen( argv[0], "r" );
else
        yyin = stdin;

yylex();
printf("number of lines = %d\n",num_lines);
printf("number of columns = %d\n", num_column);
}

// Called if there is a scanner error
void scanerror() {
  if (! error) {
    errout << "Unrecognized token starting with " << yytext << endl;
    error = true;
  }
}