/*
 * =====================================================================================
 *
 *       Filename:  4-9.c
 *
 *    Description: page 68 4-9 
 *
 *        Version:  1.0
 *        Created:  2012年12月10日 17时16分15秒
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

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp=0;

void ungetch(int c);
int getch(void);

main()
{

    char s[100];
    s[0]=getch();
    int c=EOF;
    s[1]=c;
    ungetch(c);
    c=getch();
    if(c==EOF)
        printf("EOF\n");
    else
        printf("not EOF,it is %d\n",c);
    return 0;
}

void ungetch(int c)
{
    if(bufp>=BUFSIZE)
        printf("ungetch:too many characters\n");
    else
    {
        printf("succeed ungetch %c\n",c);
        buf[bufp++]=c;
    }
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}


