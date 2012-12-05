/*
 * =====================================================================================
 *
 *       Filename:  2-6.c
 *
 *    Description:  page 40
 *
 *        Version:  1.0
 *        Created:  2012年12月04日 16时50分23秒
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

void setbits(unsigned x,int p,int n,unsigned y);

main()
{
    unsigned x = 0777;
    setbits(x,3,3,06);
}

void setbits(unsigned x,int p,int n,unsigned y)
{
    int bitmask, i;
    for(i = p-1;i < p+n-1;i++) //从p到p+n位
    {
        bitmask = y & 1;
        x &= ~(1<<i); //把x的第i位置为0
        x |= (bitmask<<i); //把x的第i为 置为y的第n位
        y >>= 1;
    }
    }
}
