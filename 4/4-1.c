/*
 * =====================================================================================
 *
 *       Filename:  4-1.c
 *
 *    Description:  page 60 4-1
 *
 *        Version:  1.0
 *        Created:  2012年12月09日 21时23分05秒
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
#include <string.h>

int strrindex(char s[],char t[]);
void reverse(char s[]);
int strindex(char s[],char t[]);

main()
{
    char s[]="0123abc789abc345";
    char t[]="abc";
    printf("字符串%s在字符串%s中最右边出现的位置是:",s,t);
    int r=strrindex(s,t);
    printf("%d\n",r);
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
int strindex(char s[],char t[])
{
    int i,j,k;

    for(i=0;s[i]!='\0';i++)
    {
        for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
            ;
        if(k>0 && t[k] == '\0')
            return i;
    }
    return -1;
}
int strrindex(char s[],char t[])
{

    reverse(s);
    reverse(t);
    int r=strindex(s,t);
    return (strlen(s)-r-strlen(t));
}
