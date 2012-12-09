/*
 * =====================================================================================
 *
 *       Filename:  4-2.c
 *
 *    Description:  page 61 4-2
 *
 *        Version:  1.0
 *        Created:  2012年12月09日 22时23分29秒
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
#include <ctype.h>
#include <math.h>

double atoff(char s[]);

main()
{
    char s[]="123.45e-6";
    double r=atoff(s);
    printf("字符串%s转化为双精度浮点数为：%f\n",s,r);
}

double atoff(char s[])
{
    double val,power;
    int i,sign,sign2;
    int val2;
    
    for(i=0;isspace(s[i]);i++)
        ;
    sign=(s[i]=='-')?-1:1;
    if(s[i]=='+'||s[i]=='-')
        i++;
    for(val=0.0;isdigit(s[i]);i++)
        val=10.0*val + (s[i]-'0');
    if(s[i]=='.')
    {
        i++;
        for(power = 1.0;isdigit(s[i]);i++)
        {
            val=10.0*val+(s[i]-'0');
            power *= 10.0;
        }
    }
    if (s[i]=='e'||'E')
    {
        i++;
        if(!isdigit(s[i]))
        {
            sign2=(s[i]=='+')?1:-1;
            if(s[i]=='+'||s[i]=='-')
                i++;
            for(val2=0;isdigit(s[i]);i++)
            {
                val2=10*val2 + (s[i]-'0');
            }
        }
    }
    if(sign2==1)
        power=power/(pow(10,val2));
    else
        power=power*(pow(10,val2));
    return sign * val /power;
}
