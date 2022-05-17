/*Consider telephone book database of N clients. Make use of a
hash table implementation to quickly look up client‘s telephone
number. Make use of two collision handling techniques and
compare them using number of comparisons required to find a
set of telephone numbers*/


#include<iostream>
#include<cstring>
using namespace std;

class telephone
{
    //Data members
    unsigned long long key;
    unsigned long long mobile[10];
    string name[10];
    int address;
    int num;     // no. of records

    public:
        telephone()      //Constructor
        {
            for (int i=0;i<10;i++)
            {
                mobile[i]=0;
            }
            for (int i=0;i<10;i++)
            {
                name[i]="-";
            }
        }

        int hash_function(unsigned long long key)
        {
            return key%10;
        }

        void insert()
        {
            cout<<"Enter the no. of records you want: ";
            cin>>num;
            cout<<"\nWhich collision technique do you wnat to use?   \n1. Linear probing  \n2. Quadratic probing"<<endl;
            cout<<"Enter your choice: ";
            int ch;
            cin>>ch;
            cout<<endl;

            for (int i=0;i<num;i++)       // will iterate for no. of records that the user want.
            {
                cout<<"\nEnter the mobile no.: ";
                cin>>key;
                address=hash_function(key);  //index number.
                
                if (mobile[address]==0)      //For inserting values without collision and collision resolution techniques.
                {
                    mobile[address]=key;
                    cout<<"\nEnter the name: ";
                    cin>>name[address];
                }
                
                else 
                {
                    if (ch==1)
                    {
                        linear_probing(mobile, name, key);
                    }

                    else if (ch==2)
                    {
                        quadratic_probing(mobile, name, key);
                    }
                }
                
            }
        }

        void linear_probing(unsigned long long mobile[],string name[],unsigned long long key)
        {
            //address.
            while(mobile[address]!=0)
            {
                address++;
            }
            mobile[address]=key;
            cout<<"\nEnter the name: ";
            cin>>name[address];
        }

        void quadratic_probing(unsigned long long mobile[], string name[],unsigned long long key)
        {
            int i=1;
            while (mobile[address]!=0)
            {
                address+=(i*i);
                i++;
            }
            mobile[address]=key;
            cout<<"\nEnter the name: ";
            cin>>name[address];
        }

        void display()
        {
            cout<<"\nIndex \tName \tMobile"<<endl;      //\t:: Horizontal tab
            for(int i=0; i<10; i++)
            {
                cout<<i<<"\t"<<name[i]<<"\t"<<mobile[i]<<endl;
            }
        }
        
};

int main()
{
    telephone t;
    int choice;
    int flag=1;
    while (flag==1)
    {
        cout<<"\n-----Telephone Directory-----"<<endl;
        cout<<"1. Insert record"<<endl;
        cout<<"2. Display record"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                t.insert();
                break;

            case 2:
                t.display();
                break;

            case 3:
                cout<<"\n---EXIT---"<<endl;
                exit(0);

            default:
                cout<<"\n*INVALID CHOICE !!!"<<endl;
        }
    }
    return 0;
}
