#include <iostream>
using namespace std;
class Node{
    public:
      int data;
      Node* left;
      Node *right;
      int tag;
      
      Node(int val)
      {
          data=val;
          left=NULL;
          right=NULL;
      }
};

class Tree{
    public:
    Node *pres;
    Tree(Node *root){
        this->pres = root;
    }

    void Linkpre()
        {
        	Node *prev=NULL;
        	Node *temp;
        	
        	int flag =0;
        	
        	if(pres==NULL)
        	{
        		return;
        	}
        	do{
        		if(flag==0)
        		{
        			cout<<pres->data<<" ";
        			if(prev==NULL && pres->right==NULL && pres->left==NULL) 
                           {
                           	  flag=2;
            			   }
        		}
        		if(pres->left!=NULL && flag==0) //left descend
        			{
        				temp=pres->left;
        	            pres->left=prev;
        	            pres->tag=0;
        	            prev=pres;
        	            pres=temp;
        	            flag=0;
        			}
        		else
        		{
        			if(pres->right!=NULL && flag!=2) //right descend
        			{
        				temp=pres->right;
                        pres->right=prev;
                        pres->tag=1;
                        prev=pres;
                        pres=temp;
                        flag=0;
        			}
        			
        			else if(prev!=NULL && prev->tag==0) //left ascend
        			{
        			      temp=prev->left;
                           prev->left=pres;
                           pres=prev;
                           prev=temp;
                         if(prev==NULL && pres->right==NULL)
                           {
                           	  flag=2;
            			   }
            			   else
            			   {
            			   	 flag=1;
            			   }
            			   
        			    
        			}
        			
        			else if(prev!=NULL && prev->tag==1)
                    {
                       temp=prev->right;
                       prev->right=pres;
                       pres=prev;
                       prev=temp;
                       flag=2;
                    }
        			
        		}
        	}while(prev!=NULL || flag!=2);
        }
        
    void Linkpost(){
        	Node *prev=NULL,*temp;
        	int flag =0;
        	if(pres==NULL)
        	{
        		return;
        	}
        	do
        	{
        		if(pres->left!=NULL && flag==0){
                    temp=pres->left;
                    pres->left=prev;
                    pres->tag=0;
                    prev=pres;
                    pres=temp;
                    flag=0;
                }
                
                else
                {
                	if(pres->right!=NULL && flag!=2)
                    {
                        temp=pres->right;
                        pres->right=prev;
                        pres->tag=1;
                        prev=pres;
                        pres=temp;
                        flag=0;
                    }
                    
                    else if(prev!=NULL && prev->tag==0)
                    {
                       temp=prev->left;
                       prev->left=pres;
                       pres=prev;
                       prev=temp;
                       flag=1;
                    }
                    else if(prev!=NULL && prev->tag==1)
                     {
                       temp=prev->right;
                       prev->right=pres;
                       pres=prev;
                       prev=temp;
                       flag=2;
                    }
        		}
        		if((flag==2)||(pres->right==NULL && flag==1) || (pres->left==NULL && pres->right==NULL && flag==0))
        		{
        			cout<<pres->data<<" ";
        			flag=2;
        		}
        		
        	}while(prev!=NULL || flag!=2);
        }
        	
    void Link()
        {
            Node *prev,*temp;
            prev=NULL;
            int flag=0;
            if(pres==NULL)
              return;
            do
            {
                if(pres->left!=NULL && flag==0){
                    temp=pres->left;
                    pres->left=prev;
                    pres->tag=0;
                    prev=pres;
                    pres=temp;
                    flag=0;
                }
                else
                {
                    if(flag!=2)
                    {
                         cout<<pres->data<<" ";
                    }
                    if(prev==NULL &&pres->right==NULL){
                        flag=2;
                    }
                        
                    if(pres->right!=NULL && flag!=2)
                    {
                        temp=pres->right;
                        pres->right=prev;
                        pres->tag=1;
                        prev=pres;
                        pres=temp;
                        flag=0;
                    }
                    else if(prev!=NULL && prev->tag==0)
                    {
                       temp=prev->left;
                       prev->left=pres;
                       pres=prev;
                       prev=temp;
                       flag=1;
                    }
                    else if(prev!=NULL && prev->tag==1)
                    {
                       temp=prev->right;
                       prev->right=pres;
                       pres=prev;
                       prev=temp;
                       flag=2;
                    }
                }
            }while(prev!=NULL || flag!=2);
        }
};
int main() {
    
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    
    root->left->left=new Node(5);
    root->left->right=new Node(7);
    
    Tree tree(root);
    tree.Link();
    cout<<"\n";
    tree.Linkpre();
    cout<<"\n";
    tree.Linkpost();

    return 0;
} 
