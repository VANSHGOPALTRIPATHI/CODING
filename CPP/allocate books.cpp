#include<iostream>
using namespace std;

bool ispossible( int arr,int n,int m, int mid){
    int studentcount=1;
    int pagesum=0;
    for ( int i=0;i<=n;i++){
            if( pagesum+arr[i]<=mid){
                
                pagesum+=arr[i];
            }
            else{ studentcount++;
            if( studentcount>m&&arr[i]>mid)
{
    return false;
}
pagesum+=arr[i];
    }
}







int main(){
    int arr[4]={ 10,20,30,40};
    int start =0;
    int ans=0;
    int end=100;
    int mid= start+ ( end-start)/2;
    while( start<=end){
        if ( ispossible(arr,n,m,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=start+1;
        }
    }
    return -1;
}
