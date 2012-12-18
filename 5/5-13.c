/*
 * =====================================================================================
 *
 *       Filename:  5-13.c
 *
 *    Description: 5-13 
 *
 *        Version:  1.0
 *        Created:  2012年12月18日 21时17分44秒
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

void tail(int argc,char *argv,char *s);

int main(int argc,char *argv)
{
    FILE f=fopen("1.txt",r);
    char *s=(char *)malloc(100);
    fprintf(f,"%s",s);
    tail(argc,argv,s);
}

void tail(int argc,char *argv.char *s)
{
    if(argc!=3)
    {
        printf("error:没有输入选项数目不对\n");
        return;
    }
    else
    {
        if(argv[1][0]!='-')
        {
            printf("error:错误的选项格式\n");
            return;
        }
        else
        {
            for(i=0;argv[1][i+1]!='\0';i++)
                s[i]=argv[1][i+1];
            s[i]='\0';
            int count=atoi(s);
            
        }
    }
    char *lines[];
}
