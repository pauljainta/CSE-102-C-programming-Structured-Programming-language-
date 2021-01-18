#include<stdio.h>
int a[1000];
int M=0;
int N,sortFlag;
int menu()
{
    int op;
   printf("CHOOSE\n");

   printf("1 for entry of a list\n");
   printf("2 for printing the list\n");
   printf("3 for sorting the list\n");
   printf("4 for searching a number\n");
   printf("5 for appending a number\n");
   printf("6 for inserting a number\n");
   printf("7 for delelting a number\n");
   printf("8 for exit\n");
   printf("Enter your option:");
   scanf("%d",&op);
   return op;

}
void entry()
{
    int i=0;
    M=1;
    printf("Enter list\n");
    printf("Enter the length of the list:");
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        printf("Enter no.%d:",i+1);
        scanf("%d",&a[i]);
    }
    printf("The current length of the list is %d\n\n",N);

}
void printing()
{
    if(M)

    {   int i;
        for(i=0;i<N;i++)
        {
            printf("The no.%d number is %d\n",i+1,a[i]);
        }
        printf("The current length of the list is %d\n\n",N);
    }
    else printf("First enter 1 and give the list\n\n");



}
void sorting()
{
    int i,j,t;
    if(M)
    {
        sortFlag=1;
        for(i=0;i<N-1;i++)
        {
            for(j=i+1;j<N;j++)
            {
                if(a[i]>=a[j])
                {
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }
        printf("The current length of the list is %d\n\n",N);
    }
    else printf("First enter 1 and give the list\n\n");
}
void appending()
{
   if(M)
   {
       N++;
       int n;
       printf("Enter a number:");
       scanf("%d",&n);
       a[N-1]=n;
       printf("The current length of the list is %d\n\n",N);
   }
   else printf("First enter 1 and give the list\n\n");
}
void searching()
{
    if(M)
    {
        int t,index=-1,i;
        printf("Enter target:");
        scanf("%d",&t);
        if(sortFlag)
        {
            int low=0,mid,high=N-1;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(a[mid]==t){
                        index=mid;
                        break;

                }

                else if(t>a[mid]) low=mid+1;
                else high=mid-1;

            }



        }
        else
        {
            int i;
            for(i=0;i<N;i++)
            {
                if(t==a[i])
                {
                    index=i;
                }
            }
        }
        if(index==-1) printf("Not found\n");
        else printf("Found\n");
        printf("The current length of the list is %d\n\n",N);
    }
    else printf("First enter 1 and give the list\n\n");

}
void inserting()
{
    if(M)
    {
        N++;
        int t;
        printf("Enter the number you want to insert:");
        scanf("%d",&t);
        if(sortFlag)
        {
            a[N-1]=t;
            sorting();

        }
        else
        {
            a[N-1]=t;
            printf("The current length of the list is %d\n\n",N);
        }

    }
    else
    {
        printf("First enter 1 and give the list\n\n");
    }

}
void deleting()
{
    if(M)
    {

        int t,index=-1,i,j;
        printf("Enter the number you want to delete:");
        scanf("%d",&t);
        if(sortFlag)
        {
            int low=0,mid,high=N-1;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(a[mid]==t){
                        index=mid;
                        for(i=index;i<N-1;i++)
                        {
                            a[i]=a[i+1];


                        a[i]=0;
                        N--;
                        break;

                        }

                }

                else if(t>a[mid]) low=mid+1;
                else high=mid-1;
        }
        }
         else
        {
            for(i=0;i<N;i++)
            {
                if(t==a[i])
                {
                    index=i;
                    for(j=index;j<N-1;j++)
                    {
                        a[j]=a[j+1];
                    }
                    a[j]=0;
                    N--;
                    break;
                }

            }

        }
        if(index==-1) printf("Not found\n");
        printf("The current length of the list is %d\n\n",N);
        }
    else printf("First enter 1 and give the list\n\n");

}
int main()
{
    int s;
    while(s!=8)
    {
         s=menu();
        switch(s)
        {
            case 1:entry();
            break;
            case 2:printing();
            break;
            case 3:sorting();
            break;
            case 4:searching();
            break;
            case 5:appending();
            break;
            case 6:inserting();
            break;
            case 7:deleting();
            break;
            case 8:printf("And!YOU are OUT!\n\n");
            break;
            default:printf("WRONG CHOICE!\n\n");

        }
    }
    return 0;
}




