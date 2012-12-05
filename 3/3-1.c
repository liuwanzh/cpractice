/*
 * =====================================================================================
 *
 *       Filename:  3-1.c
 *
 *    Description:  page 47
 *
 *        Version:  1.0
 *        Created:  2012年12月05日 19时27分26秒
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

int binsearch(int x,int v[],int n);

main()
{
    int v[]={1,2,3,4,5};
    int c=binsearch(3,v,5);
    printf("%d",c);
}

int binsearch(int x,int v[],int n)
{
    int low,high,mid;

    low=0;
    high=n-1;
    mid = (low+high)/2;
    while(low<=high && v[mid]!=x)
    {
        if(x<v[mid])
            high=mid -1;
        else
            high=mid+1;
    }
    return mid;
}


