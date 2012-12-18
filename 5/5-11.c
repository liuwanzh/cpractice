/*
 * =====================================================================================
 *
 *       Filename:  5-11.c
 *
 *    Description: page 102 5-11 
 *
 *        Version:  1.0
 *        Created:  2012年12月18日 17时01分27秒
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

#define TABINC 8
#define YES 1
#define NO 0
void detab(char *s,char *ss);
void entab(char *s,char *ss,char *tab);
void settab(int argc,char *argv[],char *tab);
/* &表示\t，*表示空格 */
int main(int argc,char *argv[])
{
   char *tab;
   tab=(char *)malloc(100*sizeof(char));
   settab(argc,argv,tab); 
    char *sss="1df        567\ta";
     
   char * ss=(char *)malloc(100*sizeof(char));

    printf("%s\n",sss);
    entab(sss,ss,tab);
     printf("%s\n",ss);
    return 0;
}
#define MAXLINE 100
void settab(int argc,char *argv[],char *tab)
{
    int i,pos;
    if(argc==1)
        for(i=0;i<=MAXLINE;i++)
        {
            if(i%TABINC != 0)
               *(tab+i)=NO;
            else
                *(tab+i)=YES;
        }
    else
    {
        for(i=0;i<=MAXLINE;i++)
            *(tab+i)=NO;
        while(--argc > 0)
        {
            pos = atoi(*++argv);
            if(pos>0 && pos <=MAXLINE)
                tab[pos]=YES;
        }
    }           
}
void detab(char *s,char *ss)
{
    int i,j,n,k,pos;
    for(i=0,k=0,pos=0;*(s+i)!='\0';)
    {
        if(*(s+i)=='\t')
        {
            n=TABINC-(pos%TABINC);
            for(j=0;j<n;j++)
            {
                pos++;
                *(ss+k)=' ';
                k++;

            }
            i++;
        }
        else
        {
            pos++;
            *(ss+k)=*(s+i);
            i++;
            k++;
        }
    }
}
void entab(char *s,char *ss,char *tab)
{
    int i,j,k,l,pos;
    k=0;
    int nb=0;
    int nt=0;
    for(i=0,pos=0;*(s+i)!='\0';)
    {
        if(*(s+i)==' ')
        {
            pos++;
            if(tab[pos] == 0)
            {
                nb++;
                i++;
            }
            else
            {
                nt++;
                nb=0;
                i++;
            }
        }
        else
        {
            for(j=0;j<nb;j++)
            {
                *(ss+k)=' ';
                k++;
            }
            for(j=0;j<nt;j++)
            {
                *(ss+k)='\t';
                k++;
            }
            nb=0;nt=0;
            *(ss+k)=*(s+i);
            k++;
            i++;
            pos++;
        }
    }
    *(ss+k+1)='\0';
}
