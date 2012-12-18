/*
 * =====================================================================================
 *
 *       Filename:  5-1.c
 *
 *    Description:  page 83 5-1
 *
 *        Version:  1.0
 *        Created:  2012年12月16日 10时43分56秒
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

int getint(int *pn);
int getch(void);
void ungetch(int);

int main()
{
    int *pn;
    int x;
    pn=&x;
    getint(&x);
    printf("%d\n",x);
}

int getint(int *pn)
{
    int c,sign;
    
    while(isspace(c=getch()))
        ;
    if(!isdigit(c)&&c!=EOF && c!='+'&&c!='-')
    {
        ungetch(c);
        return 0;
    }
    sign=(c=='-')?-1:1;
    if(c=='+'||c=='-')
        c=getch();
    if(!isdigit(c))
    {
        ungetch(c);
        return 0;
    }
    else
    {
        *pn = 0;
        for(*pn = 0;isdigit(c);c=getch())
        {
            *pn=10 * (*pn) +(c-'0');
        }
        *pn *= sign;
        if(c!=EOF)
            ungetch(c);
        return c;
    }
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp=0;
int getch(void)
{
    return (bufp>0)?buf[--bufp]:getchar();
}
void ungetch(int c)
{
    if(bufp>=BUFSIZE)
        printf("ungetch:too many characters\n");
    else
        buf[bufp++]=c;
}
