#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<malloc.h>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
    int i=0,j=0,x=0,n,flag=0;
    void *p,*add[5];
    char ch,srch,b[15],d[15],c;
    printf("Enter expression terminated by #: ");
    while((c=getchar())!='#')
    {
        b[i]=c;
        i++;
    }
    n=i-1;
    printf("Given expression: ");
    i=0;
    while(i<=n)
    {
        printf("%c",b[i]);
        i++;
    }
    printf("\n\n\t Symbol Table\n\n");
    printf("Symbol\tAddress \t Type\n");
    while(j<=n)
    {
        c=b[j];
        if(isalpha(toascii(c)))
        {
            p=malloc(c);
            add[x]=p;
            d[x]=c;
            printf("%c\t%p\t Identifer\n",c,p);
            x++;
        }
        else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='=')
        {
            p=malloc(c);
            add[x]=p;
            d[x]=c;
            printf("%c\t%p\t Operator\n",c,p);
            x++;
        }
        else if(isdigit(c))
        {
            p=malloc(c);
            add[x]=p;
            d[x]=c;
            printf("%c\t%p\t Constant\n",c,p);
            x++;
        }
    j++;
    }
    printf("\n\nEnter symbol is to be searched: ");
    cin>>srch;
    for(i=0;i<=x;i++)
    {
        if(srch==d[i])
        {
            printf("\nSymbol %c found at address: %p\n",srch,add[i]);
            flag=1;
        }
    }
    if(flag==0)
    printf("\nSymbol not found");
    getchar();
    return 0;
}