/*
 * =====================================================================================
 *
 *       Filename:  4-12.c
 *
 *    Description: page 75 4-12 
 *
 *        Version:  1.0
 *        Created:  2012年12月15日 18时23分41秒
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

void itoa(int n,char s[]);

int main()
{
    char s[100];
    itoa(345,s);
    printf("%s\n",s);
}

void itoa(int n,char s[])
{
    static int i=0;
    if(n/10)
        itoa(n/10,s);
    s[i++]=n%10+'0';
    s[i]='\0';
}
