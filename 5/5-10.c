/*
 * =====================================================================================
 *
 *       Filename:  5-10.c
 *
 *    Description: 5-10 
 *
 *        Version:  1.0
 *        Created:  2012年12月18日 15时17分49秒
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
#define NUMBER '0'

double val[MAXVAL];
double cacul(char s[],int argc,char *argv[]);
void push(double f);
double pop(void);
int getch(void);
void ungetch(int);
int getop(char s[],int argc,char *argv[]);
int sign=1;
int sp=0;
int count=0;

main(int argc,char *argv[])
{
    char s[100];
    cacul(s,argc,argv);
    return 0;
}
double cacul(char s[],int argc,char *argv[])
{
    int type;
    double op2;
    double quyu1,quyu2;
    double result;
    while((type =  getop(s,argc,argv))!='q')
    {
        switch(type)
        {
            case NUMBER:
                push(sign * (atof(s)));
                sign=1;
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
                printf("result comes\t%.8g\n",result);
                return result;
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

int getop(char s[],int argc,char *argv[])
{
    count++;
    char* temp;
    char c;
    int i;
    if(count>argc-1)
    {
        return '\n';
    }
    else
    {
        temp=argv[count];
        c=temp[0];
        if(!isdigit(c)&&c!='.'&&c!='-')
            return c;
        for(i=0;argv[count][i]!='\0';i++)
        {
            c=argv[count][i];
            if(c=='-')
            {
                if(!isdigit(argv[count][i+1])) //只是单独的减号
                {
                    return '-';
                }
                else
                {
                    sign=-1;
                }
            }
            int j=0;
            if(isdigit(c))
            {
                while(isdigit(s[j++]=c=argv[count][i++]))
                    ;
            }
            if(c=='.')
                while(isdigit(s[++j]=c=argv[count][i++]))
                    ;
            s[j]='\0';
           // if(c!=EOF)
             //   ungetch(c);
            return NUMBER;
        }      
     }
}

