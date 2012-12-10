/*
 * =====================================================================================
 *
 *       Filename:  4-6.c
 *
 *    Description: page 67 4-6 
 *
 *        Version:  1.0
 *        Created:  2012年12月10日 15时44分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  liuwanzh, liuwanzh@gmail.com
 *   Organization:  SYSU - Lab501
 *
 * =====================================================================================
 */
/* 这里只增加除了e，s，p以外的23个字母为名字的变量 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAXVAL 100
#define NUMBER '0'
#define SIN 's'
#define EXP 'e'
#define POW 'p'
#define VAR '#'

double val[MAXVAL];
char var_count;
double cacul(char s[]);
void push(double f);
double pop(void);
int getch(void);
void ungetch(int);
int getop(char s[]);
int sign=1;
int sp=0;
double variable[27];

int main()
{
    variable[0]=4.0;
    char s[100];
    double r=cacul(s);
}

double cacul(char s[])
{
    int type;
    double op2;
    double quyu1,quyu2;
    double result;
    
    while((type =  getop(s))!='q')
    {
        switch(type)
        {
            case NUMBER:
                push(sign * (atof(s)));
                sign=1;
                break;
            case VAR:
                push(variable[var_count-'a']);
                break;
            case 's':
                push(sin(pop()));
                break;
            case 'e':
                push(exp(pop()));
                break;
            case 'p':
                quyu1=pop();
                quyu2=pop();
                push(pow(quyu2,quyu1));
                break;
            case '+':
                quyu1=pop();
                quyu2=pop();
               push(quyu1+quyu2);
                // push(pop()+pop());
                break;
            case '*':
                push(pop()*pop());
                break;
            case '-':
                op2=pop();
                push(pop()-op2);
                break;
            case '/':
                op2=pop();
                if(op2!=0.0)
                    push(pop()/op2);
                else
                    printf("error,zero divisor\n");
                break;
            case '%':
                quyu1=pop();
                quyu2=pop();
                if(quyu2>=0)
                {
                    op2=((int)quyu2%((int)quyu1));
                    push(op2);
                }
                else
                {
                    push(-((-(int)quyu2) % (int)quyu1));
                }
                break;
            case '\n':
                result=pop();
                printf("\t%.8g\n",result);
                break;
            default:
                printf("error:unknown command %s\n",s);
                return -1;
                }                
    }
    return result;
}
    



void push(double f)
{
    if(sp<MAXVAL)
        val[sp++]=f;
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

int getop(char s[])
{
    int i,c;
    i=0;
    while((s[0]=c=getch())==' '||c=='\t')
        ;
    s[1]='\0';
    if(c>='a'&&c<='z')
    {
        if(c=='s'&&(getch()=='i'&&getch()=='n'))
            return 's';   
        if(c=='e'&&(getch()=='x'&&getch()=='p'))
            return 'e';
        if(c=='p'&&(getch()=='o'&&getch()=='w'))
            return 'p';
        else
        {
            var_count=c;
            if(!isdigit(c=getch()))
            {
                return VAR;
            }
        }
    }
    else if(!isdigit(c)&&c!='.')
    {
        //不是数字也不是26个字母
        if(c!='-')
            return c;
        else
        {
            if(!isdigit(c=getch()))//减号
            {
                ungetch(c);
                return '-';
            }
            
            else //负号
            {
                i++;
                c=getch();
            }
        }
    }
    if(isdigit(c))
    {
        s[i]=c;
        while(isdigit(s[++i]=c=getch()))
            ;
    }
    if(c=='.')
        while(isdigit(s[++i]=c=getch()))
            ;
    s[i]='\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
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