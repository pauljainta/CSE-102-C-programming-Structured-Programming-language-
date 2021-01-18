#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

void gotoxy(int x,int y)
{
   COORD C={x,y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),C);
}
int l,to;
struct daytype
{
    int month;
    int day;
    int year;
}date;
struct transaction
{
    int TID;
    char des[1000];
    int Ttype;
    struct daytype Tdate;
    int amount;
};
struct account
{
    int account_no;
    char account_name[1000];
   struct transaction history;
    struct daytype account_open_date;
    int balance;
}s;
void open()
{
    l=5022;
    printf("Enter your name:");
    scanf("%s",s.account_name);
    printf("Date:\n");
    scanf("%d",&s.account_open_date.day);
    scanf("%d",&s.account_open_date.month);
    scanf("%d",&s.account_open_date.year);
    printf("\nYour account number is %d\n",l);
    printf("Enter description:");
    scanf("%s",s.history.des);


}
void depositing()
{
    printf("Enter the amount of money:");
    scanf("%d",&s.balance);
    printf("Enter date:");
    scanf("%d",&s.history.Tdate.day);
    scanf("%d",&s.history.Tdate.month);
    scanf("%d",&s.history.Tdate.year);

}
void withdrawing()
{
    printf("Enter the amount of money:");
    scanf("%d",&s.history.amount);
    printf("Enter date:");
    scanf("%d",&s.history.Tdate.day);
    scanf("%d",&s.history.Tdate.month);
    scanf("%d",&s.history.Tdate.year);
    s.balance=s.balance-s.history.amount;

}
void showbalance()
{
    printf("Your current account balance is %d\n",s.balance);
    scanf("%d",&s.history.amount);

}
void moneytransfer()
{
    printf("Enter the account no. to which you want to transfer money:");
    scanf("%d",&to);
    printf("Enter the amount of money you want to transfer:");
     scanf("%d",&s.history.amount);
     printf("Enter date:");
    scanf("%d",&s.history.Tdate.day);
    scanf("%d",&s.history.Tdate.month);
    scanf("%d",&s.history.Tdate.year);
    s.balance=s.balance-s.history.amount;
}
void history()
{
    printf("Your account opening date was:");
    printf("Day:%d\n",s.account_open_date.day);
     printf("Month:%d\n",s.account_open_date.month);
     printf("Year:%d\n",s.account_open_date.year);
    printf("Description:\n");
    puts(s.history.des);


}

int menu()
{
    int option;
    gotoxy(10,12);
    printf("CHOOSE\n");
     gotoxy(14,14);
    printf("0 for opening account\n");
     gotoxy(14,16);
    printf("1 for  depositing money\n");
     gotoxy(14,18);
    printf("2 for withdrawing money\n");
     gotoxy(14,20);
    printf("3 for showing transaction history\n");
     gotoxy(14,22);
    printf("4 for showing account balance\n");
     gotoxy(14,24);
    printf("5 for transfer\n");
     gotoxy(14,26);
    printf("6 for exit\n");
     gotoxy(10,30);
    printf("Enter your oiption:");
    scanf("%d",&option);
    getch();

    system("cls");
    return option;
}
int main()
{
    int t;
    do
    {
        t=menu();
        switch(t)
        {
            case 0:open();
            break;
            case 1:depositing();
            break;
            case 2:withdrawing();
            break;
            case 4:showbalance();
            break;
            case 3:history();
            break;
            case 5:moneytransfer();
            break;
            default: break;
        }
    }while(t!=6);
    return 0;
}
