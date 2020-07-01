#include<iostream>
#include<cstring>
#include<string>
#include <stdlib.h>
#include<iomanip>
#include<dos.h>
#include <ctime>
#include<queue>
using namespace std;
string login="admin";
string password="udit2070";
class visiter{
public:
    int aadharcard_no;
    int vehicle;
    int visiting_flat;
    int pass;
    time_t start, finish;
    void entering_visiter()
    {
        cout<<"enter your aadharcard_no"<<endl;
        cin>>aadharcard_no;
        cout<<"no for vehicles you have"<<endl;
        cin>>vehicle;
        cout<<"flat you are visiting "<<endl;
        cin>>visiting_flat;
        cout<<"enter passcode provided by the resident"<<endl;
        cin>>pass;
        time(&start);

        cout<<setw(60)<<"|||||WELCOME TO ELDECO UTHOPIA|||||"<<endl;
        return ;
    }
    float exiting_visiter()
    {
        time(&finish);
        difftime(finish, start);

        cout << "Time = " << difftime(finish, start)<<"seconds"<<endl;
        cout<<"charges 10 rupees per hours"<<endl;
        return difftime(finish,start)*10*vehicle/3600;
    }
};
class flat{
private:
    float electricity_balance;
    int passcode;
public:
    int flat_no;
    string name_of_owner;
    int size_of_family;
    int flat_area;
    bool present;
    void install()
    {
        cout<<"ENTER YOUR NEW FLAT NUMBER :"<<endl;
        cin>>flat_no;

        cout<<"ENTER YOUR NAME :"<<endl;
        cin>>name_of_owner;

        cout<<"ENTER NUMBER OF PEOPLE IN YOUR FAMILY :"<<endl;
        cin>>size_of_family;

        cout<<"ENTER SIZE OF FLAT IN SQUARE FEET:"<<endl;
        cin>>flat_area;

        cout<<"CHOOSE A PASSCODE:(only share with the visiters only)"<<endl;
        cin>>passcode;
        present=true;

        electricity_balance=0;
        cout<<"WELCOME TO THE SOCIETY :"<<name_of_owner<<endl;
    }
    void PayTheBill()
    {
        int AddMoney;
        cout<<"ENTER THE MONEY YOU WANT ADD TO YOUR AMOUNT :"<<endl;
        cin>>AddMoney;
        if(AddMoney>0)
        {
        electricity_balance+=AddMoney;
        }
        else
        {
            cout<<"Enter a valid amount"<<endl;
        }
        cout<<"YOUR CURRENT BALANCE IS :"<<electricity_balance<<endl;
    }
    void showYourDetails()
    {
        cout<<"NAME :"<<name_of_owner<<endl;
        cout<<"FLAT NUMBER :"<<flat_area<<endl;
        cout<<"NUMBER OF PEOPLE IN THE FLAT : "<<size_of_family<<endl;
        cout<<"ENTER THE ELECTRICITY BILL : "<<electricity_balance<<endl;

    }
    void visiting_charges(float c)
    {
        electricity_balance=electricity_balance-c;
        cout<<c<<"rupees deducted for visiter parking charges from account of flat : "<<flat_no<<endl;
        cout<<"NOW YOUR CURRENT BALANCE IS :"<<electricity_balance<<endl;
    }
    void shop()
    {
        float price[5]={20,15,5,25,1};
        cout<<"PRESS 0 for NOODLES : 20"<<endl;
        cout<<"PRESS 1 for PASTA : 15"<<endl;
        cout<<"PRESS 2 for EGG : 5"<<endl;
        cout<<"PRESS 3 for SODA 250ml : 25"<<endl;
        cout<<"PRESS 4 for candy : 1"<<endl;
        float total_bill=0.0;
        int a=1;
        queue<int>shopping_list;
        int choice;
        int quantity;
        for(int i=0;a==1;i++)
        {
            cout<<"choose what do you want to add to the cart : "<<endl;
            cin>>choice;
            cout<<"enter the quantity : "<<endl;
            cin>>quantity;
            float cost=price[choice]*quantity;
            shopping_list.push(cost);
            cout<<"to continue shopping enter 1 and to exit and pay the bill enter 0"<<endl;
            cin>>a;
        }
        while(!shopping_list.empty())
        {
            total_bill=total_bill+shopping_list.front();
            shopping_list.pop();
        }
        cout<<"THE TOTAL BILL IS :"<<total_bill<<endl;
        cout<<"enter your passcode to pay"<<endl;
        int passc;
        cin>>passc;
        if(passc==passcode && electricity_balance>=total_bill)
        {
            electricity_balance=electricity_balance-total_bill;
            cout<<"PAYMENT WAS SUCCESSFUL"<<endl;
            cout<<"|| MONEY DEDUCTED FROM YOUR ACCOUNT ||"<<endl;
        }
        else
        {
            cout<<"PAYMENT ERROR : you don't have enough balance in your account OR the passcode is wrong"<<endl;
        }
    }
};
int main()
{
    system("Color 7C");
    cout<<setw(75)<<"*******************************************"<<endl;
    cout<<setw(60)<<"ELDECO UTOPIA"<<endl;
    cout<<setw(75)<<"*******************************************"<<endl;
    int choose;
     flat arr[100];
     visiter vis[20];
    int p=0;
   int a=0;
    int v=0;
    while(a==0)
    {
    cout<<"enter 1 if you are new to the society :"<<endl;
    cout<<"enter 2 if you want to pay your electricity bill :"<<endl;
    cout<<"enter 3 if you want to view all resident's details :"<<endl;
    cout<<"enter 4 if you want to visit a resident's house:"<<endl;
    cout<<"enter 5 if you are exiting from a resident's house:"<<endl;
    cout<<"enter 6 to purchase from shop :"<<endl;
    cout<<"enter 7 to Exit from the software"<<endl;
    cout<<"ENTER YOUR CHOOSE"<<endl;
    cin>>choose;
    switch(choose)
    {
        case 1:
            arr[p].install();
            arr[p].showYourDetails();
            p++;
            break;

        case 2:
            //THIS WILL HELP YOU TO PAY THE ELECTRICITY BILL
            int id;
            cout<<"ENTER YOUR flat number:"<<endl;
            cin>>id;
            for(int g=0;g<=p-1;g++)
            {
                if(arr[g].flat_no==id)
                {
                    arr[g].PayTheBill();
                    arr[g].showYourDetails();
                }
            }
            break;
        case 3:
            {
            cout<<"YOUR ARE REQUIRED TO LOG IN AS ADMINISTRATOR :"<<endl;
            cout<<"Login : "<<endl;
            string l;
            cin>>l;
            cout<<"Password : "<<endl;
            string pa;
            cin>>pa;
            if(login==l)
            {
            for(int i=0;i<p;i++)
                {
                    arr[i].showYourDetails();
                    cout<<"<--------------------------->"<<endl;
                }
            }
        break;
            }
        case 4:
            {
            vis[v].entering_visiter();
            v++;
            break;
            }
        case 5:
            {
            cout<<"PLEASE ENTER THE FLAT YOU VISITED VISITING"<<endl;
             int f;
             cin>>f;
            for(int w=0;w<=v-1;w++)
             {
            if(f==vis[w].visiting_flat)
            {
            float cost=vis[w].exiting_visiter();
            for(int i=0;i<=p-1;i++)
            {
                if(arr[i].flat_no==vis[w].visiting_flat)
                {
                    arr[i].visiting_charges(cost);
                }
            }
            //v++;
            }
             }
        break;
            }
        case 6:
            cout<<"GROCERY SHOP"<<endl;
            cout<<"please enter your flat number"<<endl;
            int f_number;
            cin>>f_number;
            for(int k=0;k<=p-1;k++)
            {
                if(f_number==arr[k].flat_no)
                {
                    cout<<"WELCOME"<<arr[k].name_of_owner<<endl;
                    arr[k].shop();
                }
            }
            break;
        case 7:
            a=1;
            break;

    }
    }
    cout<<"EXITING THE SYSTEM, BYE!!"<<endl;
    return 0;
}
