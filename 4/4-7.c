/*
 * =====================================================================================
 *
 *       Filename:  4-7.c
 *
 *    Description: page 67 4-7 
 *
 *        Version:  1.0
 *        Created:  2012年12月10日 16时34分10秒
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

void ungets(char s[]);
void ungetch(int c);

main()
{
    char s[100];
    int c,i;
    i=0;
    while((c=getchar())!='q')
    {
        s[i++]=c;
    }
    ungetch(c);
    printf("%c\n",getch());
    ungets("98");
    printf("%c\n",getch());
    printf("%c\n",getch());
    return 0;
}
void ungetch(int c)
{
    if(bufp>=BUFSIZE)
        printf("ungetch:too many characters\n");
    else
        buf[bufp++]=c;
}
void ungets(char s[])
{
    int i;
    for(i=0;s[i]!='\0';i++)
    {
        ungetch(s[i]);
    }
}
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}


