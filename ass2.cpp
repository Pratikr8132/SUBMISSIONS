/*Company maintains employee information as employee ID,
name, designation, and salary. Allow user to add, delete
information of employee. Display information of particular
employee. If employee does not exist an appropriate message is
displayed. If it is, then the system displays the employee details.
Use index sequential file to maintain the data.*/











#include<iostream>
#include<fstream>
using namespace std;

class student
{
    public:
        //Data members
        int roll_no;
        char name[50];
        char div[5];
        char address[50];

        //Member functions.
        void set_data()
        {
            cout<<"\nEnter the name of the student: ";
            cin>>name;
            cout<<"\nEnter the roll no. of the student: ";
            cin>>roll_no;
            cout<<"\nEnter the division: ";
            cin>>div;
            cout<<"\nEnter the address of the student: ";
            cin>>address;
        }
        void show_data()
        {
            cout<<"\nName: "<<name<<endl;
            cout<<"Roll No.: "<<roll_no<<endl;
            cout<<"Division: "<<div<<endl;
            cout<<"Address: "<<address<<endl;
        }
        int ret_roll()
        {
            return roll_no;
        }
};

void write_record()
{
    ofstream outfile; //outfile is an object for ofstream class.
    outfile.open("student.data", ios::binary | ios::app);

    student s;
    s.set_data();
    outfile.write((char*)&s, sizeof(s));
    outfile.close();
}

void display()
{
    ifstream infile;
    infile.open("student.data", ios::binary);

    student s;
    while (infile.read((char*)&s, sizeof(s)))
    {
        s.show_data();
    }
    infile.close();
}

void search(int n)
{
    ifstream infile;
    infile.open("student.data", ios::binary);
    int flag=0;
    student s;
    while(infile.read((char*)&s, sizeof(s)))
    {
        if (s.ret_roll()==n)
        {
            s.show_data();
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        cout<<"\n---RECORD not found---";
    }
    infile.close();
}

void delete_record(int n)
{
    student s;
    ifstream infile;
    infile.open("student.data", ios::binary);
    ofstream outfile;
    outfile.open("temp.data", ios::binary | ios::out);

    while (infile.read((char*)&s, sizeof(s)))
    {
        if (s.ret_roll()!=n)
        {
            outfile.write((char*)&s, sizeof(s));
        }
    }
    infile.close();
    outfile.close();
    remove("student.data");
    rename("temp.data", "student.data");
}



int main()
{
    int f=1;
    while(f==1)
    {
        cout<<"\n-----MENU-----"<<endl;
        cout<<"1.Insert records \n2.Display records \n3.Search records \n4.Delete records \n5.Exit"<<endl;
        cout<<"Enter your choice: ";
        int ch;
        cin>>ch;

        switch(ch)
        {
            case 1:
                int n;
                cout<<"Enter the number of records: ";
                cin>>n;
                for (int i=0;i<n;i++)
                {
                    write_record();
                }
                break;
            
            case 2:
                cout<<"\n------LIST OF RECORDS------";
                display();
                break;

            case 3:
                cout<<"Enter the roll no. you want to search: ";
                int key;
                cin>>key;
                search(key);
                break;

            case 4:
                cout<<"Enter the roll no. you want to delete: ";
                int d;
                cin>>d;
                delete_record(d);
                cout << "\nRecord Deleted";
                break;

            case 5:
                f=0;

            default:
                cout<<"\n***INVALID CHOICE***"<<endl;
                break;
        }

    } 
    return 0;
}

