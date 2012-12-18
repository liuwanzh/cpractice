/*
 * =====================================================================================
 *
 *       Filename:  5-8.c
 *
 *    Description:  5-8
 *
 *        Version:  1.0
 *        Created:  2012年12月17日 21时11分56秒
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

static char daytab[2][13]= {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};
int day_of_year(int year,int month,int day);
void month_day(int year,int yearday,int *pmonth,int *pda);
int main()
{
    int r;
    int *month;
    int a,b;
    month=&a;
    int *day;
    day=&b;
    r=day_of_year(2012,1,30);
    printf("%d\n",r);
    month_day(2012,30,month,day);
    printf("%d,%d\n",*month,*day);
    return 0;
}

int day_of_year(int year,int month,int day)
{
    int i,leap;
    leap=year%4==0 && year%100 != 0 || year % 400 ==0;
    if(daytab[leap][month]<day)
        return 0;
    for(i=1;i<month;i++)
    {
        day+=daytab[leap][i];
    }
    return day;
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
            yearday-=daytab[leap][i];
        *pmonth=i;
        *pday=yearday;
    }
}
