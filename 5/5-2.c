/*
 * =====================================================================================
 *
 *       Filename:  5-2.c
 *
 *    Description:  5-2
 *
 *        Version:  1.0
 *        Created:  2012年12月17日 09时38分15秒
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

int getfloat(float *pn);
int getch(void);
void ungetch(int c);
int main()
{
    float *pn;
    float a=1.0;
    pn=&a;
    getfloat(pn);
    printf("%f\n",a);
    return 0;
}
int getfloat(float *pn)
{
    float power;
    int c,sign;
    while ((c=getch())==' ')
        ;
    if(!isdigit(c)&&c!=EOF && c!='+' && c!='-')
    {
        ungetch(c);
        return 0;
    }
    sign=(c=='-')?-1:1;
    if(c=='+'||c=='-')
        c=getch();
    for(*pn=0;isdigit(c);c=getch())
        *pn=10 * *pn + (c-'0');
    if(c=='.')
    {
        c=getch();
        for(power=1.0;isdigit(c);c=getch())
        {
            *pn=10 * *pn +(c-'0');
            power*=10;
        }
    }
    *pn=*pn * sign /power;
    return c;
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
