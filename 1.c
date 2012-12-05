/*
 * =====================================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  example
 *
 *        Version:  1.0
 *        Created:  2012年12月01日 20时48分37秒
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
#define T_COUNT 4
#define MAXLINE 100
main()
{
    printf("%d",T_COUNT);
    int i,j;
    char after[100];
    char c;
    for (i=0;i<100 && (c=getchar())!='\n' ;i++)
    {
        if(c!='\t')
            after[i]=c;
        else
        {
            for (j=0;j < MAXLINE ;j++)
            {
                after[i+j]='y';
            }
            i=i+T_COUNT;
        }
    }
    for (;i<100;i++)
    {
        after[i]='a';
    }
    printf("for ends;");
    //after[i]='\0';
    printf("%s",after);
    return 0;
}

