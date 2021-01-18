#include<stdio.h>
int factorial(int n);
int main()
{
    int n,f;
    printf("Enter the value of n:");
    scanf("%d",&n);
    if(n<0) printf("The factorial of %d cannot be determined",n);
    else{
    f=factorial(n);
    printf("The factorial of %d is %d",n,f);
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







