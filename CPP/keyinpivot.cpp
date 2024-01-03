#include<iostream>
using namespace std;
    int getpivot( int arr[],int size){
        int start=0;
        int end=size-1;
        int mid=start=( end-start)/2;
        while( start< end){
            if ( arr[mid]>arr[0]){
                start=mid+1;
            }
            else {
                end=mid;
            }
        }
         return start;
    }
    int binary(int arr[],int start,int end,int k){
        int s=start;
        int e=end;
        int mid=s+(e-s)/2;
        while(s<=e){
            if( arr[mid]==k){
                return mid;
            }
            else if( k> arr[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return -1;
    }
    int getkey( int arr[], int size,int key){
        int pivot=getpivot( arr,6);
        if ( key>= arr[pivot]&& key<=arr[size-1]){
           return binary(arr,pivot,size-1,3);
        }
        else{
            return binary( arr,0,pivot-1,3);
        }
    }

int main(){
    
    int arr[6]={7,8,9,1,2,3};
    cout<<"the index of pivot element is "<<getpivot(arr,6)<<endl;
    cout<<" the key is "<<binary<<endl;
    

}