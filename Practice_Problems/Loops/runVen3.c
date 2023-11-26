//vending Machine
#include<stdio.h>
void display(int price1,int price2,int price3,int price4,int q1,int q2,int q3,int q4)
{
   printf("Available Drinks:\n");
   printf("1.Coke(price:%d,Available:%d)\n",price1,q1);
   printf("2.Pepsi(price:%d,Available:%d)\n",price2,q2);
   printf("3.Sprite(price:%d,Available:%d)\n",price3,q3);
   printf("4.7UP(price:%d,Available:%d)\n",price4,q4);

}
int user_input1()
{
    int choice;
    printf("Enter the drink number you want to purchase(1-4):");
    scanf("%d",&choice);
    return choice;
}
int user_input2()
{
    int quantity;
    printf("Enter the quantity you want to purchase:");
    scanf("%d",&quantity);
    return quantity;
}
int check_availability(int q1,int q2,int q3,int q4,int choice,int quantity)
{
    if (choice==1)
    {
        if (quantity<q1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(choice==2)
    {
        if (quantity<q2)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
    else if(choice==3)
    {
        if (quantity<q3)
        {
            return 3;
        }
        else
        {
            return 0;
        }
    }
    else if(choice==4)
    {
        if (quantity<q1)
        {
            return 4;
        }
        else
        {
            return 0;
        }
    }


}
int calculate_bill(int price,int quantity)
{
    int total_bill;
    total_bill=price*quantity;
    return total_bill;
        
}
int update_stock(int q,int quantity)
{
    int new_q;
    new_q=q-quantity;
    return new_q;
}
int main()
{
    int x,price1=5,price2=7,price3=7,price4=3,q1=10,q2=15,q3=15,q4=25,choice,quantity;
    printf("welcome to the vending machine!\n");
    display(price1,price2,price3,price4,q1,q2,q3,q4);
    choice=user_input1();
    quantity=user_input2();
    x=check_availability(q1,q2,q3,q4,choice,quantity);
    if(x==1)
    {
       printf("you have ordered %d Cokes for a total of %d$\n",quantity,calculate_bill(price1,quantity));
       q1=update_stock(q1,quantity);        
    }
    else if(x==2)
    {
        printf("you have ordered %d pepsis for a total of %d$\n",quantity,calculate_bill(price2,quantity));
        q2=update_stock(q2,quantity);
    }
    else if(x==3)
    {
        printf("you have ordered %d sprites for a total of %d$\n",quantity,calculate_bill(price3,quantity));
        q3=update_stock(q3,quantity);
    }
    else if(x==4)
    {
        printf("you have ordered %d 7UPs for a total of %d$\n",quantity,calculate_bill(price4,quantity));
        q4=update_stock(q4,quantity);
    }
    else
    {
        printf("sorry! the maximum number of stock has been ordered\n");
    }
       
    display(price1,price2,price3,price4,q1,q2,q3,q4);
    return 0;
}
