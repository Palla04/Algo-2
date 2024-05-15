#include<stdio.h>
int integer_expo(int x,int n){
    
    int z=x;
    int y=1;
    int N=n;
    int c=0;
    while(N>0)
    {
        if(N%2==0)
        {
            N = N/2;
            
            if(N>0)
            {
                z=z*z;
                c++;
            }
            
        }
        
        else{
            y=z*y;
              c++;
            N = N/2;
            
            if(N>0)
            {
                z=z*z;
                c++;
            }
            
        }
        
    }
    if(N<0)
    {
        printf("Output: %d", y);
    }
    printf("Value of the operation: %d\n",y);
    printf("\nNumber of multiplication: %d", c);
}
int main()
{
    int base, exponent;
    
    // Input base and exponent
    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);
    
    integer_expo(base,exponent);
    return 0;
}
