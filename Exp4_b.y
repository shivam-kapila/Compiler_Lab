%{
    #include<stdio.h>
    int valid=1;
%}
%token digit letter
%%
    start : letter s
    s :     letter s
        | digit s
        |
        ;
%%
int yyerror()
{
    printf("Its is not an identifier!\n");
    valid=0;
    return 0;
}
int main()
{
    printf("Enter a name to be tested for identifier: ");
    yyparse();
    if(valid)
    {
        printf("It is an identifier!\n");
    }
}