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

void preorder(node * root){
	stack<node *>s;
	while(root!=NULL)
	{
		cout<<root->data<<" ";
		if(root->right!=NULL)
		{
			s.push(root->right);
		}
		if(root->left!=NULL)
		{
			root=root->left;
		}
		else
		{
			if(!s.empty())
			{
				root=s.top();
				s.pop();
			}
			else
			{
			  break;
			}
			
		}
	}
	
}
void postorder(node* root)
{
    stack<node*>st;
    cout<<"\nIterative Postorder:-"<<endl;
    do
    {
        while(root!=NULL)
        {
            if(root->right!=NULL)
            {
                st.push(root->right);
            }
            st.push(root);
            root=root->left;  
        }
        if(!st.empty())
        {
            root=st.top();
            st.pop();
            if(root->right != NULL && !st.empty() && root->right == st.top())
            {
                st.pop();
                st.push(root);
                root=root->right;
                
            } 
            else
	        {
	            cout<<root->data<<" ";
	            root=NULL;
	        }
        }
    }
    while(!st.empty());
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
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    postorder(root);
	display();
	return 0;
}
