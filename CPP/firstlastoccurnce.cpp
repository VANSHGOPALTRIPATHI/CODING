#include<iostream>
using namespace std;
int   firstoccurence( int arr[],int size,int key){
        int answer=0;
      int  s=0;
      int   e=size-1;
      int mid=s+(e-s)/2;
      while(s<=e){
        if(arr[mid]==key){
            answer=mid;
            e=mid-1;
        }
        if(key<arr[mid]){
            e=mid-1;
        }
        if(key>arr[mid]){
            s=mid+1;
        }
        int mid=s+(e-s)/2;
      }
      return answer;

  }

  
  int   lastoccurence( int arr[],int size,int key){
        int answer=0;
      int  s=0;
      int   e=size-1;
      int mid=s+(e-s)/2;
      while(s<=e){
        if(arr[mid]==key){
            answer=mid;
            s=mid+1;
        }
        if(key<arr[mid]){
            e=mid-1;
        }
        if(key>arr[mid]){
            s=mid+1;
        }
        int mid=s+(e-s)/2;
      }
      return answer;

  }


int main(){
    int arr[5]={6,9,90,900,900};
    int brr[6]={1,3,5,7,9,100};
    cout<<" the first and lst occurnece of 900 is "<<firstoccurence(arr,5,900)<<endl;
     cout<<" the first and last occurnece of 900 is "<<lastoccurence(arr,6,900)<<endl;
return 0;
}