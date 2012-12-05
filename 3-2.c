/*
 * =====================================================================================
 *
 *       Filename:  3-2.c
 *
 *    Description:  page 49 3-2
 *
 *        Version:  1.0
 *        Created:  2012年12月05日 19时55分36秒
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

void escape(char s[],char t[]);
void anti_escape(char s[],char t[]);

main()
{
    char t[]="hello\nworld\t";
    char s[100];
//    printf("%s",t);
    escape(s,t);
    printf("%s",s);
    printf("\n");

    char tt[100];
    anti_escape(tt,s);
    printf("%send",tt);
}

void anti_escape(char s[],char t[])
{
    int i,j;
    for (i=0,j=0;t[i]!='\0';i++,j++)
    {
        switch(t[i])
        {
            case '\\':
                switch (t[++i])
                {
                    case 'n':
                        s[j]='\n';
                        break;
                    case 't':
                        s[j]='\t';
                        break;
                    default:
                        s[j]='\\';
                        break;
                }
                break;
            default:
                s[j]=t[i];
                break;
        }
    }
}
void escape(char s[],char t[])
{
    int i,j;
    for(i=0,j=0;t[i]!='\0';i++,j++)
    {
        switch(t[i]) 
        {
            case '\n':
                {
                s[j]='\\';
                j++;
                s[j]='n';
                break;
                }            
            case '\t':
                s[j]='\\';
                s[++j]='t';
                break;
            default:
                s[j]=t[i];
                break;
        }
    }
    s[j]='\0';
}

