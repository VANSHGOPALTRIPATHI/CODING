#include<iostream>
using namespace std;
int  main(){

    int arr[5]={  5,7,9,1,2};
     int start=0;
     int end=4;
     int mid=start+(end-start)/2;
     while( start<end){
        if( arr[mid]>=arr[0]){
            start=mid+1;
        }
        else{
            end=mid;
        }
        mid=start+(end-start)/2;
     }
     cout<<arr[start];
}