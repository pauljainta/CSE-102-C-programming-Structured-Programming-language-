#include<stdio.h>
int factorial(int n)
{
    if(n==0) return 1;
    else
    {
        int s=1,i;
        for(i=1;i<=n;i++)
        {
            s=s*i;
        }
        return s;
    }
}
long int nCr (int n ,int r)
{
    long int combination;
    combination=factorial(n)/(factorial(n-r)*factorial(r));
    return combination;
}
int main()
{
    int a,b,summation;
    for(a=0;a<=9;a++)
    {
        summation=0;
        for(b=0;a-b>=b;b++)
        {
            summation=summation+nCr(a-b,b);

        }
        printf("%d ",summation);




    }
    return 0;
}



