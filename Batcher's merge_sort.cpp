#include <iostream>
#include<stack>
using namespace std;

class Network{
	public:
		void compare(int &a,int &b){
			if(a>b)
			{
				int temp=a;
				a=b;
				b=temp;
			}
			
		}
		int *sort(int ar[],int lo,int no)
		{
			if(no>1)
			{
				int mid=no/2;
				int m=mid;
				int n=no-mid;
				int *u = new int[m];
				int *v=new int[n];
				u=sort(ar,lo,m);
				v=sort(ar,lo+mid,n);
				int *s=merge(u,v,m,n);
				delete[] u;
				delete[] v;
				return s;
			}
			else
			{
				int *s=new int[1];
				s[0]=ar[lo];
				return s;
			}
		}
		
		int *merge(int u[],int v[],int m,int n)
		{
			int *s;
			int i,j,c;
			if(m==0)
			{
				s=new int[n];
				s[0]=v[0];
			}
			else if(n==0)
			{
				s=new int[m];
				s[0]=u[0];
			}
			else if(m==1 && n==1)
			{
				compare(u[0],v[0]);
				s=new int[2];
				s[0]=u[0];
				s[1]=v[0];
			}
			else
			{
				int x,y;
				if(m%2==1)
				{
				   x=m/2+1;
				}
				else
				{
				    x=m/2;	
				}
				if(n%2==1)
				{
				   y=n/2 + 1;
				}
				else
				{
				    y=n/2;	
				}
				
				int *ou = new int[x];
				int *ov = new int[y];
				for(i=0,j=0;i<m;i+=2,j++)
				{
					ou[j]=u[i];
				} 
				for(i=0,j=0;i<n;i+=2,j++)
				{
					ov[j]=v[i];
				} 
				int *a = merge(ou,ov,x,y);
				
				delete[] ou;
				delete[] ov;
				
				int *eu = new int[m/2];
				int *ev = new int[n/2];
				for(i=1,j=0;i<m;i+=2,j++)
				{
					eu[j]=u[i];
				} 
				for(i=1,j=0;i<n;i+=2,j++)
				{
					ev[j]=v[i];
				} 
				int *b = merge(eu,ev,m/2,n/2);
				delete[] eu;
				delete[] ev;
				
				if(m%2==0 && n%2==0)
				{
					c = m/2 + n/2 - 1;
				}
				else
				{
					c = m/2 + n/2;
				}
				for(i=1;i<=c;i++)
				{
					compare(b[i-1],a[i]);
				}
				s=new int[m+n];
				s[0]=a[0];
				cout<<" ";
				for(i=1,j=0;i<=c;i++)
				{
					s[++j]=b[i-1];
					s[++j]=a[i];
				}
				if(m%2==0 && n%2==0)
				{
					s[++j]=b[m/2 + n/2 - 1];
				}
				else if(m%2==1 && n%2==1)
				{
					s[++j]=a[ m/2 + n/2 + 1];
				}
				
				delete[] a;
			    delete[] b;
			}
			return s;
		}
};

int main()
{
	Network S;
	int n,i;
	cout<<"Enter the size of the array\n";
	cin>>n;
	int *ar=new int[n];
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the element: ";
		cin>>ar[i];
	}
	for(i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	int *k = S.sort(ar,0,n);
	cout<<"\n";
	for(i=0;i<n;i++){
		cout<<k[i]<<" ";
	}
	delete[] k;
	delete[] ar;
	return 0;
}
