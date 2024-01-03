#include<iostream>
using namespace std;
int print(int arr[], int size){
    for(int i=0;i<=size;i++){
        cout<<arr[i]<<" ";
        cout<<"is in index"<<i<<" "<<endl;
    }
}
int main(){
    int arr[3]={3,7,9};
    print(arr,2);
    
    int brr[4]={87,4,4,5,};
    print(brr,3);

return 0;
}