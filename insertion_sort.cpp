#include<iostream>
using namespace std;
int insertion_sort(int n,int A[])
{
    for(int i=1;i<n;i++)
    {
        int temp=A[i];
        int j=i-1;
        while(A[j]>temp && j>=0)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=temp;
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
    insertion_sort(n,A)

    return 0;
}