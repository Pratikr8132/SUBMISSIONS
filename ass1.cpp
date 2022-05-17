/*A book consists of chapters, chapters consist of sections and sections consist of 
subsections. Construct a tree and print the nodes. Find the time and space requirements 
of your method.*/


#include<iostream>
using namespace std;

struct node
{
    char label[50];   // for storing the name of chapter,section and sub-section.
    int chcount;      // for counting the number of child nodes.
    node *child[50];   // for storing the address of child nodes.
}* root;

class tree
{
    public:
        tree()    //default constructor.
        {
            root=NULL;
        }

        void insert();
        void display();
};

void tree::insert()
{
    root=new node();
    cout<<"Enter the name of the book: ";
    cin>>root->label;
    cout<<"Enter the no. of chapter in the book: ";
    cin>>root->chcount;

    for (int i=0;i<root->chcount;i++)    //i=no. of chapters,.
    {
        root->child[i]=new node();
        cout<<"Enter the name of the chapter: ";
        cin>>root->child[i]->label;
        cout<<"Enter the no. of section you want in the chapter: ";
        cin>>root->child[i]->chcount;

        for (int j=0;j<root->child[i]->chcount;j++)    //j=no. of sections.
        {
            root->child[i]->child[j]=new node();
            cout<<"Enter the name of the sections: ";
            cin>>root->child[i]->child[j]->label;
            cout<<"Enter the no. of sub-section you want in the section: ";
            cin>>root->child[i]->child[j]->chcount; 

            for (int k=0;k<root->child[i]->child[j]->chcount;k++)      //j=no. of sub-sections.
            {
                root->child[i]->child[j]->child[k]=new node();
                cout<<"Enter the name of the sub-sections: ";
                cin>>root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}


void tree::display()
{
    if (root!=NULL)
    {   
        cout<<"------------------------------"<<endl;
        cout<<"          BOOK HEIRARCHY      "<<endl;
        cout<<"------------------------------"<<endl;

        cout<<"\nBook name: "<<root->label<<endl;
        for (int i=0;i<root->chcount;i++) 
        {
            cout<<"-->"<<root->child[i]->label<<endl;
            for (int j=0;j<root->child[i]->chcount;j++)
            {
                cout<<"---->"<<root->child[i]->child[j]->label<<endl;
                for (int k=0;k<root->child[i]->child[j]->chcount;k++)
                {
                    cout<<"------>"<<root->child[i]->child[j]->child[k]->label<<endl;
                }
            }
        }
    }
}

int main()
{
    int ch;
    tree t;
    int f=1;
    while (f==1)
    {
        cout<<"\n-----MENU-----"<<endl;
        cout<<"1. Insert  \n2. Display   \n3. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                t.insert();
                break;
            
            case 2:
                t.display();
                break;
            
            case 3:
                cout<<"---EXIT---"<<endl;
                exit(1);

            default:
                cout<<"Invalid input!! try again-->"<<endl;
        }
    }
return 0;
}