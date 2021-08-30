#include<iostream>
using namespace std;
int bubble_sort(int n, int A[])
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}
int main()
{
    int n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    bubble_sort(n,A);
    return 0;
}