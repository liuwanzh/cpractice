/*
 * =====================================================================================
 *
 *       Filename:  4-10.c
 *
 *    Description: page 68 4-10 
 *
 *        Version:  1.0
 *        Created:  2012年12月10日 18时49分42秒
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

int count=0;
char now[]="4 5 +";
double val[MAXVAL];
double cacul(char s[]);
void push(double f);
double pop(void);
int getop(char s[]);
int sign=1;
int sp=0;

int main()
{
    char s[100];
    double r=calline(s);
}

int line_p=0;
int c;
int calline(char r[])
{
    //now="4 5 +";
    while(getchar()!='q')
    {
        while((r[0]=c=now[line_p++])==' '||c=='\t')
        {
        }
        r[1]='\0';
        while(now[line_p]!='\0')
        {
            cacul(r);
        }
   }
}

int getop(char s[])
{
    int i,c;
    while(now[line_p++]==' '|| now[line_p]=='\t')
    {
        s[0]=c=now[line_p];
    }
    s[1]='\0';
    if(!isdigit(c)&&c!='.'&&c!='-'&&c!='s'&&c!='e'&&c!='p')
        return c;
    line_p++;
    if(c=='-'&&!isdigit(c=now[line_p]))
    {
        //   line_p--;
        return '-';
    }
    line_p--;
    if(c=='s'&&(now[++line_p]=='i'&&now[++line_p]=='n'))
        return 's';   
    if(c=='e'&&(now[++line_p]=='x'&&now[++line_p]=='p'))
        return 'e';
    if(c=='p'&&(now[++line_p]=='o'&&now[++line_p]=='w'))
        return 'p';
    i=0;
    if(c=='-')
    {
        i++;
        c=now[++line_p];
    }
    if(isdigit(c))
    {
        s[i]=c;
        c=now[++line_p];
        s[++i]=c;
        while(isdigit(s[i]))
        {
            c=now[++line_p];
            s[++i]=c;
            count++;
        }
    }
    if(c=='.')
        while(isdigit(s[++i]=c=now[++line_p]))
            ;
    s[i]='\0';
    if(c!=EOF)
    {
        line_p--;
    }
    printf("%s\n",s);
    return NUMBER;
}

double cacul(char s[])
{
    int type;
    double op2;
    double quyu1,quyu2;
    double result;
    while((type = getop(s))!=EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(sign * (atof(s)));
                sign=1;
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
