/*
 * =====================================================================================
 *
 *       Filename:  5-7.c
 *
 *    Description:  5-7
 *
 *        Version:  1.0
 *        Created:  2012年12月17日 15时25分50秒
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

#define MAXLINE 5 //一行最多多少字
#define MAXSTOR 100
int readlines(char *lineptr[],int maxline,char *stor);
int my_getline(char *line,int maxline);

int main()
{
    FILE f;
    f=fopen("1.txt",r);
    char *stor;
    char *lineptr[100];
    readlines(lineptr,100,stor,f);
    return 0;
}

#define MAXLEN 100 //每一行最多多少
int readlines(char *lineptr[],int maxlines,char *stor)
    int len,nlines;
    char *p;
    char line[MAXLEN];
    p=stor;
    nlines=0;
    char *pt = stor + MAXSTOR;
    while((len=my_getline(line,MAXLINE,f))>0)
    {

        if(nlines>=maxlines || p+len > pt )
        { printf("out \n");
            return -1;
        }
        else
        {
            line[len-1]='\0';
            strcpy(p,line);
            lineptr[nlines++]=p;
            p+=len;
        }
        return nlines;
    }
}

int my_getline(char *line,int maxline)
{
    static int i=0;
    char c;
    char *begin = line;
    char *linetop=line+maxline;
    while((c=getchar())!='\n' && line<linetop)
    {
        *line=c;
        line++;
        printf("%c\n",c);
    }
    return line-begin;
}
