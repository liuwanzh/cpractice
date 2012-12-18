/*
 * =====================================================================================
 *
 *       Filename:  5-9.c
 *
 *    Description: page 98 5-9 
 *
 *        Version:  1.0
 *        Created:  2012年12月18日 13时53分59秒
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

int day_of_year(int year,int month,int day);
void month_day(int year,int yearday,int *pmonth,int *pday);

static int daytab[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
                         {0,31,29,31,30,31,30,31,31,30,31,30,31}};
int main()
{
    int t=day_of_year(2012,2,28);
    printf("%d\n",t);
    int month,day;
    month_day(2012,20,&month,&day);
    printf("%d/%d\n",month,day);
    return 0;
}


void month_day(int year,int yearday,int *pmonth,int *pday)
{
    int i,leap;
    leap=year%4==0 && year%100!=0 || year%400 == 0;
    int maxday;
    maxday=(leap)?366:365;
    if(yearday>maxday)
    {
        printf("error:yearday too large\n");
        return;
    }
    else
    {
        for(i=1;yearday>daytab[leap][i];i++)
            yearday-=*(*(daytab+leap)+i);
        *pmonth=i;
        *pday=yearday;
    }
}
int day_of_year(int year,int month,int day)
{
    int i,leap;
    leap=year%4 == 0 && year%100 !=0 || year%400 == 0;
    for(i=1;i<month;i++)
    {
        day+=(*(*(daytab+leap)+i));
    }
    return day;
}
