/*
 * =====================================================================================
 *
 *       Filename:  3-3.c
 *
 *    Description: page 52 
 *
 *        Version:  1.0
 *        Created:  2012年12月08日 13时20分09秒
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

void expand(char s1[],char s2[]);

main()
{
    char s1[]="-a-gh-n-p7-9-";
    char s2[100];
    expand(s1,s2);
    printf("%s  to\n%s\n",s1,s2);
}

void expand(char s1[],char s2[])
{
    int i=0,j=0;
    int k;
    char from,to;
    int flag=0;
    if(s1[0]=='-')
    {
        s2[j++]=s1[0];
        i++;
    }
    for(;s1[i]!='\0';i++)
    {
      
        if(s1[i]=='-')
        {
            i++;
            if(s1[i]=='\0')
            {
                s2[j++]=s1[--i];
                break;
            }
            else
            {
                to=s1[i];
                for(k=0;k<to-from;k++)
                {
                    s2[j]=from+k+1;
                    j++;
                }
                from=s2[j-1];
                flag=1;
            }
        }
        else
        {
            from=s1[i];
            s2[j++]=from;
        }
    }
    s2[j]='\0';
}
