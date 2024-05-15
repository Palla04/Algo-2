#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void cm_lps(char* p,int M,int* lps)
{
    int i=1,len=0;
    lps[0] = 0;
    while(i<M)
    {
        if(p[i]==p[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else if(len!=0)
        {
            len = lps[len-1];
        }
        else
        {
            lps[i]=0;
            i++;
        }
    }
    
    for(int i=0;i<M;i++)
    {
        cout<< lps[i] <<" , ";
    }
}

void kmp(char* t,char* p)
{
   int M = strlen(p);
   cout<<"the length :"<<M<<endl;
   int N = strlen(t);
   cout<<"the length :"<<N<<endl;
   int lps[M];
   cm_lps(p,M,lps);
   int i=0,j=0;
   while(i<N)
   {
       if (p[j] == t[i])
       {
            j++;
            i++;
        }
        // mismatch after j matches
        else if (j != 0) 
        {
                j = lps[j - 1];
        }
        else
        {
                i = i + 1;
             
        }
           if (j == M)
        {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }
     
   }
}

int main() 
{
   char txt[] = "onionionspl";
   char pat[] = "onions";
   kmp(txt,pat);
}
