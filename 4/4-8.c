/*
 * =====================================================================================
 *
 *       Filename:  4-8.c
 *
 *    Description: page 67 4-8 
 *
 *        Version:  1.0
 *        Created:  2012年12月10日 16时53分10秒
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

#define BUFSIZE 1
char buf[BUFSIZE];
int bufp=0;

void ungetch(int c);
int getch(void);

int main()
{
    int c;
    int i=0;
    char s[100];
    while((c=getchar())!='q')
    {
        s[i++]=c;
    }
    ungetch(c);
    ungetch(c);
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


