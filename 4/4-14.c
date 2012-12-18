/*
 * =====================================================================================
 *
 *       Filename:  4-14.c
 *
 *    Description: page 77 
 *
 *        Version:  1.0
 *        Created:  2012年12月15日 19时58分57秒
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

#define swap(t,x,y) {t _z; \
                     _z=x; \
                     x=y;  \
                     y=_z;}

int main()
{
    int x=1;
    int y=2;
    swap(int,x,y);
    printf("%d,%d\n",x,y);
}
