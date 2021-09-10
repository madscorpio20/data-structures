#include<iostream>
using namespace std;
int select_sort(int n,int A[])
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(A[j]<A[i])
            {
                int temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<A[i];
    }

}

int main()
{
    int n;
    int A[n];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    select_sort(n,A);
    
    return 0;
}