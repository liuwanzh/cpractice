/*
 * =====================================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  2-9 page41
 *
 *        Version:  1.0
 *        Created:  2012年12月04日 22时49分46秒
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

int bitcount(unsigned x);

main()
{
    unsigned a = 0707;
    printf("%d\n",bitcount(a));
}

int bitcount(unsigned x)
{
    int count=0;
    while(1)
    {
        x &= x-1;
        count++;
        if(x==0)
            break;
    }
    return count;
}
