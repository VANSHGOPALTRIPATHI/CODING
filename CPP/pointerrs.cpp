#include<iostream>
using namespace std;
int main(){


    int arr[10]={0,2,3,4,5,6,7,8,9,1};
    cout<<" adress of 1st location is"<<arr<<endl;
     cout<<" adress of 1st location is"<<&arr[0]<<endl;
     cout<<&arr[1]<<endl;
    cout<<*&arr[7]<<endl;
    cout<<*(arr+4)<<endl;
    int i=5;
    cout<<i[arr]<<endl;//index can be writeen outside
    cout<<*( i+ arr);//some new styles


    int *p=(arr+2);
    cout<<p<<endl;
    cout<<*p;
}
