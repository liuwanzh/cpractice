/*
 * =====================================================================================
 *
 *       Filename:  5-3.c
 *
 *    Description:  5-3
 *
 *        Version:  1.0
 *        Created:  2012年12月17日 11时20分50秒
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

void mystrcat(char *s,char *t);

/*要如何初始化指针呢？？*/
int main()
{
    char s[100];
    strcpy(s,"abc");
    char *t="de";
    mystrcat(s,t);
    printf("%s\n",s);
    return 0;
}

void mystrcat(char *s,char *t)
{
    char temp;
    while(*s!='\0')
        s++;
    while(*t!='\0')
    {
        *s=*t;
        t++;
        s++;
    }
    *s='\0';
}
