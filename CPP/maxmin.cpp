#include<iostream>
using namespace std;
 int getmax(int arr[],int size){
    int max=0;
    for(int i=0;i<=size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
 }
    int getmin(int arr[],int size){
    int min=120000;
    for(int i=0;i<=size;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return min;
    }
int main(){
    
        int size;
    cout<<"enter the size of aray"<<endl;
    cin>>size;
    int arr[10];
    for(int i=0;i<=size;i++){
        cin>>arr[i];
    }
    cout<<"the maximum value is "<<getmax(arr,size)<<" "<<endl;
    cout<<"the minimun value is "<<getmin(arr,size)<<" "<<endl;
}
