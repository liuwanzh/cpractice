/*
 * =====================================================================================
 *
 *       Filename:  4-13.c
 *
 *    Description: page 75 4-13 
 *
 *        Version:  1.0
 *        Created:  2012年12月15日 18时42分30秒
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

void reverse(char s[]);

int main()
{
    char s[100];
    strcpy(s,"12345");
    printf("yuanlai:%s\n",s);
    reverse(s);
    printf("houlai:%s\n",s);
    return 0;
}

void reverse(char s[])
{
    void reverser(int begin,int end,char s[]);

    int len=strlen(s);
    reverser(0,len-1,s);
}
void reverser(int begin,int end,char s[])
{
    char temp;
    int i=begin;
    int j=end;
 //   static int i=0;
 //   static int j=len;
    printf("j is %d\n",j);
    if(i<j)
    {
        temp=s[i];
        s[i++]=s[j];
        s[j--]=temp;
        reverser(i,j,s);
    }
    printf("%d--%d\n",i,j);
} 
