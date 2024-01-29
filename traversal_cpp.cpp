#include<bits/stdc++.h>
using namespace std;
typedef struct node{
	public:
		int data;
		struct node *left;
		struct node *right;
}node;
struct node* newnode(int val)
{   
            
          struct node *temp = new struct node;
	   	  temp->data = val;
	   	  temp->left=NULL;
	   	  temp->right=NULL;
	   	  return temp;
}
struct node* insert(node* root, int key)
{
	if(root==NULL)
	{
		return newnode(key);
		
	}
	if(key<root->data)
	{
		root->left=insert(root->left,key);
	}
	else
	{
		root->right=insert(root->right,key);
	}
	
	return root;
}
void display()
{
   printf("display \n"); 
}

void inorder(node * root){

	stack<node*>s;
	do{
		while(root != NULL)
		{
		    s.push(root);
		    root=root->left;
		}
		if(!s.empty())
		{
			root=s.top();
			s.pop();
			cout<<root->data<<" ";
			root=root->right;
		}
		else{
		   break;
		}
	}while(1);
}
int main()
{
	node *root=NULL;
	
	int size,i,a;
	
// 	root=insert(root,4);
// 	root=insert(root,5);
// 	root=insert(root,7);
	cout<<"\nEnter size: ";
	cin>>size;
	for(i=0;i<size;i++)
	{
		cout<<"\nEnter data to be added: ";
		cin>>a;
		root = insert(root,a);
 	}

    inorder(root);
	display();
	return 0;
}
