/*
 * =====================================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  example2
 *
 *        Version:  1.0
 *        Created:  2012年12月04日 14时03分17秒
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

int any(char s1[],char s2[]);
main()
{
    char s1[]="abcdefg";
    char s2[]="zs";
    printf("%d",any(s1,s2));
    return 0;
}

int any(char s1[],char s2[])
{
    int i,j;
    i=j=0;
    while(s1[i]!='\0')
    {
        while(1)
        {
            if(s2[j]==s1[i])
            {
                return i;
            }
            else if(s2[j]=='\0')
            {
                j=0;
                i++;
                break;
            }
            else
                j++;
        }
    }
    return -1;
}
