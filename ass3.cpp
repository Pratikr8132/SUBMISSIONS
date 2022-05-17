//Begining with an empty binary search tree, construct Binary Search Tree by 
//inserting the values in the order given. After constructing tree :
//1. Insert new node.
//2. Find number of nodes in the longest path
//3. Minimum data value found in the tree
//4. Change a tree so that the nodes of left and and right pointers are swapped at every node.
//5. Search a value


#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
  int key;
  struct node *l;
  struct node *r;
} *r;

class BST
{
public:
  BST ()
  {
    r == NULL;
  }
  void insert (node * tree, node * newnode);
  int longpath (node * root);
  void minimum (struct node *node);
  node *swap (node * root);
  void search (node * root, int data);
  void inorder(node*root);
};

void BST::insert (node * tree, node * newnode)
{
  if (r == NULL)
    {
      r = new node;
      r->key = newnode->key;
      r->l = NULL;
      r->r = NULL;
      cout << "Root node is added" << endl;
      return;
    }
  if (tree->key == newnode->key)
    {
      cout << "Key is already present in BST" << endl;
      return;
    }
  if (tree->key > newnode->key)
    {
      if (tree->l != NULL)
	{
	  insert (tree->l, newnode);
	}
      else
	{
	  tree->l = newnode;
	  (tree->l)->l = NULL;
	  (tree->l)->r = NULL;
	  cout << "key added to left subtree" << endl;
	  return;
	}
    }
  if (tree->key < newnode->key)
    {
      if (tree->r != NULL)
	{
	  insert (tree->r, newnode);
	}
      else
	{
	  tree->r = newnode;
	  (tree->r)->l = NULL;
	  (tree->r)->r = NULL;
	  cout << "key added to right subtree" << endl;
	  return;
	}
    }
}

int BST::longpath (node * root)
{
  if (root == NULL)
    return 0;
  int lctr = longpath (root->l);
  int rctr = longpath (root->r);
  if (lctr > rctr)
    return (lctr + 1);
  else
    return (rctr + 1);

}

void BST::minimum (struct node *node)
{
  struct node *current = node;
  while (current->l != NULL)
    {
      current = current->l;
      cout << "Minimum value in BST is : " << current->key << endl;
    }
  return;
}

node* BST ::swap (node * root)
{
   node *temp;
  if(root==NULL)
  {
      return 0;
  }
     
  temp = root->l;
      root->l = root->r;
      root->r = temp;
      swap(root->l);
      swap(root->r);
  return 0;
}

void BST::search (node * root, int data)
{   
    int depth =0;
    
    if(root != NULL)
    {
        depth++;
        if(root->key == data)
        {
            cout<<"Key present in the BST at depth : "<<depth<<endl;
            return;
        }
        else if(root->key > data)
        {
            search(root->l,data);
        }
        else
        {
            search(root->r,data);
        }
    }
    else
    {
        cout<<"key not found in BST"<<endl;
        return;
    }
    
    

}

void BST:: inorder(node*root)
{
   if(root == NULL)
   {
      return ;
   }
   if(root !=NULL)
   {
       inorder(root->l);
       cout<<root->key<<" ";
       inorder(root->r);
   }
}

int main ()
{
  BST b;
  int c, path,item;
  node *t;

  while (1)
    {
      cout << "Operation on bst" << endl;
      cout << "1.Insert" << endl;
      cout << "2.Lonest path in bst" << endl;
      cout << "3.Minimum value in bst" << endl;
      cout << "4.Swap" << endl;
      cout << "5.Search value from bst" << endl;
      cout << "6.Exit" << endl;
      cout << "Enter your choice : ";
      cin >> c;
      switch (c)
	{
	case 1:
	  t = new node;
	  cout << "Enter the number to be inserted : ";
	  cin >> t->key;
	  b.insert (r, t);
	  cout << endl;
	  break;

	case 2:
	  path = b.longpath (r);
	  cout << "longest path in bst is : " << path << endl;
	  cout << endl;
	  break;

	case 3:
	  b.minimum (r);
	  cout << endl;
	  break;

    case 4:
      cout<<"Before swap order is : ",b.inorder(r),"\n";
      b.swap(r);
      cout<<"After swap order is : ",b.inorder(r),"\n";
      b.swap(r);
      cout<<endl;
      break;
      
    case 5:
      cout<<"Enter the number to be searched : ";
      cin>>item;
      b.search(r,item);
      cout<<endl;
      break;

	case 6:
	  exit (1);

	default:
	  cout << "wrong choice" << endl;
	}

    }
}
