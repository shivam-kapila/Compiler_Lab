%{
int COMMENT=0;
%}
identifier [a-zA-Z][a-zA-Z0-9]*
%%
#.* {printf("%s is a PREPROCESSOR DIRECTIVE",yytext);}
int |
float |
char |
double |
while |
for |
struct |
typedef |
do |
if |
break |
continue |
void |
switch |
return |
else |
goto {printf("\n%s is a KEYWORD",yytext);}
"/*" {COMMENT=1;}{printf("\n%s is a COMMENT",yytext);}
{identifier}\( {if(!COMMENT)printf("\nFUNCTION\n%s",yytext);}
\{  {if(!COMMENT)printf("BLOCK BEGINS");}
\}  {if(!COMMENT)printf("BLOCK ENDS");}
{identifier}(\[[0-9]*\])? {if(!COMMENT) printf("\n%s is an IDENTIFIER",yytext);}
\".*\" {if(!COMMENT)printf("\n%s is a STRING",yytext);}
[0-9]+ {if(!COMMENT) printf("\n%s is a NUMBER",yytext);}
\)(\:)? {if(!COMMENT);ECHO;}
\( ECHO;
= {if(!COMMENT)printf("\n%s is an ASSIGNMENT OPERATOR",yytext);}
\<= |
\>= |
\< |
== |
\> {if(!COMMENT) printf("\n%s is a RELATIONAL OPERATOR",yytext);}
%%
int main(int argc, char **argv)
{
    FILE *file;
    file=fopen("Input.cpp","r");
    if(!file)
    {
        printf("Could not open the file");
        exit(0);
    }
    yyin=file;
    yylex();
    printf("\n");
    return(0);
}
int yywrap()
{
    return(1);
}