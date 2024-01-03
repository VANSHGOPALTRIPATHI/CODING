#include<iostream>
using namespace std;
#include<vector>
 int main(){
    int arr[5]={ 1,2,3,4,5};
    int k;
    int temp[5]={0};
    
    cout<<" enter the value "<<endl;
    cin>>k;
    int i=0;
    for ( ;i<5;i++){
        temp[(i+k)%5]=arr[i];
    }
    arr[]=temp;
    
    
 

}