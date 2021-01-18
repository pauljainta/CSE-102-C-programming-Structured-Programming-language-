#include<stdio.h>
int factorial(int n)
{
    if(n==0) return 1;
    else
    {
        int s=1,i;
        for(i=1;i<=n;i++){

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
    int i,n,j,k,s;
    printf("Enter the number of lines:");
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=n-i-1;j++)
        {
            printf(" ");
        }
        for(k=0;k<=i;k++)
        {
            s=nCr(i,k);
            printf("%d ",s);
        }
        printf("\n");
    }
    return 0;
}


