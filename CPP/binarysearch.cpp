#include<iostream>
using namespace std;
int main(){
    int arr[5]={ 4 ,6 ,8 ,9 ,10};
    int  key ;
    cout<<"enter the key";
    cin>>key;
     int start=0;
     int end=4;
     int mid= start + (end-start)/2;
     while( start<=end){

            if( arr[mid] == key){
                return mid;

            }
            if( key< arr[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid= start + (end-start)/2;
     }
     return -1;
     
}
