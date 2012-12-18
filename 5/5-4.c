/*
 * =====================================================================================
 *
 *       Filename:  5-4.c
 *
 *    Description:  5-4.c
 *
 *        Version:  1.0
 *        Created:  2012年12月17日 11时42分34秒
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

int strend(char *s,char *t);

int main()
{
    char *s="abcdczde";
    char *t="de";
    printf("%d\n",strend(s,t));
}

int strend(char *s,char *t)
{
    char *tt=t;
    while(*s!='\0')
    {
        if(*s==*t)
        {
            while(*s==*t)
            {
                s++;
                t++;
            }
            if(*(s-1)=='\0')
                return 1;
            else
                t=tt;
        }
        else
        {
            s++;
        }
    }
    return 0;
}

