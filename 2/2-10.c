/*
 * =====================================================================================
 *
 *       Filename:  2-10.c
 *
 *    Description:  page 43 2-10
 *
 *        Version:  1.0
 *        Created:  2012年12月04日 23时13分33秒
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

void lower(char a[]);

main()
{
    char a[]="ASDWXxsdw";
    lower(a);
    printf("%s\n",a);
}

void lower(char a[])
{
    int i=0;
    for(;a[i]!='\0';i++)
    {
        a[i]= (a[i]>='A'&& a[i]<='Z')? (a[i]+'a'-'A'):a[i];
     }
}
