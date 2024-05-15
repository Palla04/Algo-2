#include<stdio.h>
int polynomial_eva(int A[],int n,int x){
    int p=A[n];
    int i=n;
    while(i>=1)
    {
        p=p*x + A[i-1];
        i--;
    }
    
    printf("\n the solution of the polynomial equation is: %d",p);
}
int main(){
    int n,x,i;
    int A[10];
    printf("Enter the max degree of x: ");
    scanf("%d",&n);
    
    printf("Enter the value of x: ");
    scanf("%d", &x);
    
    for(i=0;i<=n;i++)
    {
        printf("Enter the value of A[%d]: ",i);
        scanf("%d",&A[i]);
    }
    polynomial_eva(A,n,x);
    return 0;
}
