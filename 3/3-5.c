/*
 * =====================================================================================
 *
 *       Filename:  3-5.c
 *
 *    Description: page 53 3-5 
 *
 *        Version:  1.0
 *        Created:  2012年12月08日 15时55分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  liuwanzh, liuwanzh@gmail.com
 *   Organization:  SYSU - Lab501
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void itob(int n,char s[],int b);
char change(int n);
void reverse(char s[]);

int main()
{
    char s[100];
    int b=16;
    int n=26;
    itob(n,s,b);
    printf("%d变成%d进制以后，为：%s\n",n,b,s);
}

void reverse(char s[])
{
    int c,i,j;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}
char change(int n)
{
    if(n>9)
        return 'A'+n-10;
    else
        return '0'+n;
}
void itob(int n,char s[],int b)
{
    int i=0;
    do{
        s[i++]=change(n%b);
        n/=b;
    }while(n!=0);
    s[i]='\0';
    reverse(s);
}

