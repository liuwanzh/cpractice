
/*
 * =====================================================================================
 *
 *       Filename:  4-3.c
 *
 *    Description: page 65 4-3 
 *
 *        Version:  1.0
 *        Created:  2012年12月10日 09时39分57秒
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
double cacul(char s[]);
void push(double f);
double pop(void);
int getch(void);
void ungetch(int);
int getop(char s[]);
void my_getline(char s[]);
int sign=1;
int sp=0;
int line_p = 0;

char now[MAXVAL]; //   = "4 6 *\n";

int main()
{
    my_getline(now);
    char s[100];
    double r=cacul(s);
    printf("%lf\n", r);
}

void my_getline(char *s)
{
    scanf("%[^\n]s", s);
    int len = strlen(s);
    s[len] = getchar();
    s[++len] = 0;
    
//    getline(s, MAXVAL-1, stdin);
//    k
//    strcpy(s, "4 6 *");
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

int getop(char s[])
{
    int i,c;
    while((s[0]=c=getch())==' '||c=='\t')
        ;
    s[1]='\0';
    if(!isdigit(c)&&c!='.'&&c!='-')
        return c;
    if(c=='-'&&!isdigit(c=getch()))
    {
        ungetch(c);
        return '-';
    }
    i=0;
    if(c=='-')
    {
        i++;
        c=getch();
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
    return now[line_p++];
}
void ungetch(int c)
{
    line_p--;
}
