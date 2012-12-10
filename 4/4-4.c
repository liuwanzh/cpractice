/*
 * =====================================================================================
 *
 *       Filename:  4-4.c
 *
 *    Description:  page 67 4-4
 *
 *        Version:  1.0
 *        Created:  2012年12月10日 13时37分42秒
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

#define MAXVAL 100

int sp=0;
double val[MAXVAL];
void push(double f);
double pop(void);
double top(void);
void exchange(void);
void clear(void);

main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printf("firstly,push 1 2 3 4 5.\n");
    printf("pop:%f\n",pop());
    printf("after pop,sp is%d\n",sp);
    printf("top:%f\n",top());
    printf("pop after top:%f\n",pop());
    exchange();
    printf("after exchange,2 pops is:%f ",pop());
    printf("and %f\n",pop());
    clear();
    printf("after clear,pop:%f\n",pop());
    
    return 0;
}
void push(double f)
{
    if(sp<MAXVAL)
    {
        val[sp++]=f;
    }
    else
        printf("error:stack full,cant push %g\n",f);
}

double pop(void)
{
    if(sp>0)
   /*  {
        printf("sp is %d,pop %g\n",sp,val[--sp]);
        return val[++sp];
    }*/
        return val[--sp];
    else
    {
        printf("error:stack empty\n");
        return 0.0;
    }
}

double top(void)
{
    if(sp>0)
        return val[sp-1];
    else
    {
        printf("error:stack empty\n");
        return 0.0;
    }
}

void exchange(void)
{
    double temp;
    if(sp>1)
    {
        temp=val[sp-1];
        val[sp-1]=val[sp-2];
        val[sp-2]=temp;
    }
    else
    {
        printf("error:not enough number in the stack");
    }
}

void clear(void)
{
    sp=0;
}
