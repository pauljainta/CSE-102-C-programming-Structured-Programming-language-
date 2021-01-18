#include<stdio.h>
#include<windows.h>
#include<stdlib.h>


int c=0;
COORD coord= {0,0};


void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


void print_tower()
{
    int i,j;

    for(i=20; i<=100; i++)
    {
        gotoxy(i,30);
        if((i<50&&i>40)||(i<80&&i>70))
            continue;
        printf("=");
    }
    for(j=15; j<=30; j++)
    {
        gotoxy(30,j);
        printf("||");
        gotoxy(60,j);
        printf("||");
        gotoxy(90,j);
        printf("||");
    }
}


void print_box()
{
    int i;

    for(i=0; i<=8; i++)
    {
        printf("[]");
    }
}


void move_box(int s,int d)
{
    int i,j,f=29,r,a;


    if(s==1)
        a=22;
    else if(s==2)
        a=52;
    else
        a=82;


    if((s==1&&d==2)||(s==2&&d==3)||(s==3&&d==2)||(s==2&&d==1))          //range
    {
        r=30;
    }
    else if((s==1&&d==3)||(s==3&&d==1))
    {
        r=60;
    }


    if((s==1&&d==2)||(s==2&&d==3)||(s==1&&d==3))                //right shifting
    {
        for(j=f; j>=10; j--)
        {
            print_tower();
            gotoxy(a,j);
            print_box();
            Sleep(100);
            system("cls");
        }
        for(i=a; i<=a+r; i++)
        {
            print_tower();
            gotoxy(i,j+1);
            print_box();
            Sleep(100);
            system("cls");
        }
        for(j=j+1; j<=f; j++)
        {
            print_tower();
            gotoxy(i-1,j);
            print_box();
            Sleep(100);
            system("cls");
        }
    }
    else
    {
        for(j=f; j>=10; j--)
        {
            print_tower();
            gotoxy(a,j);
            print_box();
            Sleep(100);
            system("cls");
        }
        for(i=a; i>=a-r+2; i--)
        {
            print_tower();
            gotoxy(i,j+1);
            print_box();
            Sleep(100);
            system("cls");
        }
        for(j=j+1; j<=f; j++)
        {
            print_tower();
            gotoxy(i-1,j);
            print_box();
            Sleep(100);
            system("cls");
        }
    }
    print_tower();

}


void hanoi(int n,int s,int h,int d)
{
    if(n==1)
    {
        c++;
        move_box(s,d);
    }
    else
    {
        hanoi(n-1,s,d,h);
        hanoi(1,s,h,d);
        hanoi(n-1,h,s,d);
    }
}


int main()
{
    int n;

    printf("enter the number of disk : ");
    scanf("%d",&n);

    hanoi(n,1,2,3);
    gotoxy(10,32);
    printf("number of moves : %d",c);
}
