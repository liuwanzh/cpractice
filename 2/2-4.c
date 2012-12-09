/*
 * =====================================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  example
 *
 *        Version:  1.0
 *        Created:  2012年12月02日 19时21分25秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wengsht, wengsht.sysu@gmail.com
 *   Organization:  SYSU - Lab501
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

void squeeze(char a[],char b[]);
main()
{
    char a[]="qwerrtyu";
    char b[]="qux";
    squeeze(a,b);
    printf("%s\n",a);
}

void squeeze(char a[],char b[])
{
    int i,k,j;
    for(i=k=0;a[i]!='\0';i++)
    {
        for(j=0;b[j]!='\0'&&b[j]!=a[i];j++)
        {
            ;
        }
        if(b[j]=='\0')
        {
            a[k++]=a[i];
        }
    }
    a[k]='\0';
}
