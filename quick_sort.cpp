#include<iostream>
using namespace std;
int partition(int input[],int si,int ei)
{
    int pi=si;
    int pivot = input[pi];
    for(int i=si;i<=ei;i++)
    {
        if(input[i] < pivot)
        {
            pi++;
        }
    }
    
    input[si] = input[pi];
    input[pi] = pivot;
    for(int i=si,j=ei;i<pi && j>pi;)
    {
        while(input[i]<pivot)
        {
            i++;
        }
        while(input[j]>=pivot)
        {
            j--;
        }
        if(i<pi && j>pi){              
        	int temp=input[i];
        	input[i]=input[j];
        	input[j]=temp;
        	i++;
        	j--;
        }
    }
  
    return pi;
}
void quicksort(int input[],int si,int ei)
{
    if(si<ei)
    {
       int pi= partition(input,si,ei);
        quicksort(input,si,pi-1);
        quicksort(input,pi+1,ei);
    }
    return;
}
void quickSort(int input[], int size) {
    
    quicksort(input,0,size-1);
    

}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}
