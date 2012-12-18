/*
 * =====================================================================================
 *
 *       Filename:  5-5.c
 *
 *    Description:  5-5
 *
 *        Version:  1.0
 *        Created:  2012年12月17日 13时51分44秒
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

void strncpy(char *s,char *t,int n);
void strncat(char *s,char *t,int n);
int strncmp(char *s,char *t,int n);

int main()
{
    char s[100];
    char *t="abce";
    strcpy(s,"abcefaaa");
    printf("%s\n",s);
 //   strncpy(s,t,5);
 //  strncat(s,t,2);
    int re=strncmp(s,t,5);
    printf("%d\n",re);
}

void strncpy(char *s,char *t,int n)
{
    int i=0;
    while(*t!='\0' && i<n)
    {
        *s=*t;
        s++;
        t++;
        i++;
    }
    *s='\0';
}

void strncat(char *s,char *t,int n)
{
    int i=0;
    while(*s!='\0')
        s++;
    while(*t!='\0' && i<n)
    {
        *s=*t;
        t++;
        s++;
        i++;
    }
    *s='\0';
}

int strncmp(char *s,char *t,int n)
{
    int i=0;
    while(*s!='\0' && *t!='\0' && i<n)
    {
        if(*s != *t)
            return 1;
        else
        {
            s++;
            t++;
            i++;
        }
    }
    return 0;
}
