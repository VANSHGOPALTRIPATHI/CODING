#include<iostream>
using namespace std;
int main(){
    int arr[5]={ 4,6,80,9,1};
    for ( int i=0;i<5;i++){
        int j=i-1;
         int temp=arr[i];
         for ( int j=i-1;j>=0;j++){
            if ( arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else {
                break;
            }
         }

    
    arr[j+1]=temp;

    cout<<arr[i]<<" ";
    
     } }