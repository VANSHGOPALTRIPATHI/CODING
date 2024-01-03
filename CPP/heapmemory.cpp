#include<iostream>
using namespace std;
int main(){
    // dynamic memorry allocation in heap 
    new char;
    char *p= new char;
    cout<<new char<<endl;
    cout<<*p<<endl;

    new int[5];
    int *arr=new int[5];
    cout<<*arr<<endl;

    // passing n in an array by heap memory allocation


    int n;
    cin>>n;
    int *arr=new int[5];
    int sum=0;
    for ( int i=0; i<=n; i++){
        cin>>arr[i];
        sum+=arr[i];

    }
    cout<<" the sum is"<<sum<<endl;


}