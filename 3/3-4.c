/*
 * =====================================================================================
 *
 *       Filename:  3-4.c
 *
 *    Description:  page 53 3-4
 *
 *        Version:  1.0
 *        Created:  2012年12月08日 15时35分00秒
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

void itoa(int n,char s[]);
void reverse (char s[]);

int main()
{
    int n=-2147483648;
    char s[100];
    itoa(n,s);
    printf("%s\n",s);
    return 0;
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
void itoa(int n,char s[])
{
    int i,sign;
    if(n<0)
    {
        sign=-1;
    }
    i=0;
    do{
        s[i++]=abs(n%10) + '0';
    }while(abs(n/=10)>0);
   if(sign < 0)
       s[i++]='-';
    s[i]='\0';
    reverse(s);
}
