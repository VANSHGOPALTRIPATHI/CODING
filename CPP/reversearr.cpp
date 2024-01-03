#include<iostream>
using namespace std;
int main(){

    int arr[5]={65,98,4,26,4};
    int start=0;
    int end=4;
    for(int i=0;i<5;i++){
        if(start<=end){
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
          cout<<arr[i]<<" ";
    }
    
    
}