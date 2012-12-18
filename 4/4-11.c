/*
 * =====================================================================================
 *
 *       Filename:  4-11.c
 *
 *    Description: page 71 4-11 
 *
 *        Version:  1.0
 *        Created:  2012年12月15日 09时58分06秒
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
    printf("%d\n",' ');
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
int flag=1;
int getop(char s[])
{
    static int lastc = 0;
    int i,c;
    printf("lastc:%d\n",lastc);
    if(lastc == 0)
    {
        printf("lastc=0\n");
        c=getch();
    }
    else
    {
        c=lastc;
        lastc=0;
    }
    i=0;
    while((s[0]=c)==' '||c=='\t')
        c=getch();
    s[1]='\0';
  
    if(!isdigit(c)&&c!='.'&&c!='-'&&c!='s'&&c!='e'&&c!='p'&&(!(c>='a'&&c<='z')))
        return c;

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
                lastc=c;
                return VAR;
            }
        }
    }
    if(c=='-')
    {
        if(!isdigit(c=getch()))
        {
            lastc=c;
            return '-';
        }
        else
        {
            sign=-1;
        //    lastc=c;
            flag=0;
        }
    }
    else
    {
        printf("lastc is%d,c is%d\n",lastc,c);
       // lastc=c;
        flag=0;
    }
    i=0;
    if(flag!=0)
        c=getch();
    printf("c:%c\n",c);
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
    printf("s:%s\n",s);
    if(c!=EOF)
        lastc=c;
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
