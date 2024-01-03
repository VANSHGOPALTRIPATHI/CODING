#include<iostream>
using namespace std;
int  main(){
    int arr[5]={ 10 , 45,8,98,6};
    for ( int i=0; i<5;i++){
        int minindex=i;
        for ( int j=i+1;j<5;j++){
            if( arr[j]<arr[minindex]){
                minindex=j;
            }
            swap( arr[minindex],arr[i]);
        }
cout<<arr[i]<<" ";
    
    }
   
}
