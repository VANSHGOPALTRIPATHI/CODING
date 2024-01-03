#include<iostream>
using namespace std;
int main(){
    int arr[5]={ 23,67,54,78,98};
    for (int i =0; i<5;i++){
        bool swapped=false;
        for (int j=0;j<4;j++){
         
            if (arr[j]>arr[j+1]){
                swap( arr[j],arr[j+1]);
                swapped=true;
            }}
            if ( swapped= false){
                break;
            }
        
        cout<<arr[i]<<" ";

    }}