#include <iostream>
using namespace std;
void mergeSort(int input[],int si,int ei)
{
    if(si<ei)
    {
        int mid=(si+ei)/2;
        mergeSort(input,si,mid);
        mergeSort(input,mid+1,ei);
        int arr[ei-si+1];
        int k=0;
        int i,j;
        for( i=si, j=mid+1;i<=mid && j<=ei;)
        {
            if(input[i]<input[j])
            {
                arr[k]=input[i];
                k++;
                i++;
            }
            else if(input[i]>input[j])          
            {
                arr[k]=input[j];
                j++;                                               
                k++;
            }
            else if(input[i]==input[j])          
            {
                arr[k]=input[i];
                arr[k+1]=input[j];
                k+=2;
                j++;
                i++;
                
            }
            
        }       
        if(i<=mid)
        {
            while(i<=mid)
            {
                arr[k]=input[i];
                k++;
                i++;
            }
        }
        if(j<=ei)
        {
            while(j<=ei)
            {
                arr[k]=input[j];
                k++;
                j++;
            }
        }
        int l,m;
        for( l=si, m=0;l<=ei&& m<k;l++,m++)
        {
            input[l]=arr[m];
        }
        return;
    }
    
    
}
void mergeSort(int input[], int size){
    int si=0;
    int ei=size-1;
    
     mergeSort(input,si,ei);
    
}
int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}