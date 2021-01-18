#include<stdio.h>
long int nCr (int n ,int r);
int factorial(int n);
int main()
{
    int n,r;
    long int combination;
    printf("Enter the value of n:");
    scanf("%d",&n);
    printf("Enter the value of r:");
    scanf("%d",&r);
    if(n<r||n<0||r<0)
    {
        printf("WRONG INPUT");

    }
   else
   {

      combination=nCr(n,r);
      printf("The combination is %ld",combination);
   }
    return 0;
}
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

