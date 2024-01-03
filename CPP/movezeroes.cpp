#include<iostream>
using namespace std;
int main(){
    int arr[5]={1,0,8,9,0};
        int i=0;
    for( int j=0 ;j<4;j++){
        if( arr[j]!=0){
            swap( arr[j],arr[i]);
            i++;
        }
        else{
            continue;
        }
    
    
    cout<<arr[j]<<" ";

}}