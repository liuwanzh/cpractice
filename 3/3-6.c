/*
 * =====================================================================================
 *
 *       Filename:  3-6.c
 *
 *    Description:  page 53 3-6
 *
 *        Version:  1.0
 *        Created:  2012年12月08日 16时38分47秒
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
#include <math.h>
#include <string.h>

void itoa(int n,char s[],int width);
void reverse (char s[]);

int main()
{
    char s[100];
    int n=-158456;
    int width=3;
    itoa(n,s,width);
    printf("%d以至少%d宽度输出为:\n%s\n",n,width,s);
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
void itoa(int n,char s[],int width)
{
    if(n<0)
        width--;
    int i,sign,k;
    k=0;
    int temp=abs(n/10);
    int pow_temp=pow(10,width-1);
    if(temp<pow_temp)
    {
        do{
            temp*=10;
            k++;
            printf("k-now:%d.temp vs pow_temp:%d vs %d\n",k,temp,pow_temp);
        }while(temp<pow_temp);
    k--;
    }
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
    while(k)
    {
        s[i++]='*';
        k--;
    }
    s[i]='\0';
    reverse(s);
}
