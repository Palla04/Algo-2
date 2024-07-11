#include<iostream>
using namespace std;
void Increment(int A[],int k)
{
	int i=0;
	for(i=k-1;i>=0;i--)
	{
		cout<<" "<<A[i];
	}
	cout<<endl;
	
	i=0;
	while(i<k && A[i]==1)
	{
		A[i]=0;
		i=i+1;
	}
	if(i<k)
	{
		A[i]=1;
	}
}
int main()
{
	int size,count;
	cout<<"Enter the size: ";
	cin>>size;
	
	int A[100]={0};
	for (count = 0; count < (1 << size); count++) {
        Increment(A, size);
    }

	return 0;
}
