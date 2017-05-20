#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
class bst
{
    node *root;
public:
    bst()
    {
	cout<<"constructor\n";
	root=NULL;
    }
    bool isEmpty()
    {
	return (root==NULL);
    }
    void insert(int data)
    {
	node *t=new node;
	node *parent;
	cout<<data<<endl;
	t->data=data;
	t->left=NULL;
	t->right=NULL;
	if(isEmpty())
	    {
		cout<<"Enters isEmpty\n";
		root=t;
	    }
	else
	    {
		node *ptr;
		ptr=root;
		while(ptr!=NULL)
		    {
			parent=ptr;
			if(data>ptr->data)
			    ptr=ptr->right;
			else
			    ptr=ptr->left;
		    }
		if(data>parent->data)
		    parent->right=t;
		else
		    parent->left=t;
	    }
    }
    void preordertrav()
    {
	cout<<"PreOrder:";
	preorder(root);
    }
    void preorder(node* t)
    {
	if(t!=NULL)
	    {
		cout<<t->data<<" ";
		preorder(t->right);
		preorder(t->left);
	    }
    }
    void postordertrav()
    {
	
	postorder(root);
    }
    void postorder(node* t)
    {
	if(t!=NULL)
	    //cout<<"PostOrder:\n";
	    {
		postorder(t->left);
		postorder(t->right);
		cout<<t->data<<" ";
	    }
    }
    void inordertrav()
    {
	cout<<"Inorder:\n";
	inorder(root);
    }
    void inorder(node* t)
    {
	if(t!=NULL)
	    {
		inorder(t->left);
		cout<<t->data<<" ";
		inorder(t->right);
	    }
    }
}b;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
	b.insert(rand()%n+1);
    cout<<endl;
    b.preordertrav();
    return 0;
}
