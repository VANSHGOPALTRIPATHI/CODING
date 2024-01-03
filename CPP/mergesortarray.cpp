#include<iostream>
using namespace std;

    int merge( int arr1[], int n,int arr2[],int m, int arr3[]){
        int i=0;
        int j=0;
        int k=0;
        while( i<n && j<m){
            if( arr1[i]<arr2[j]){
                arr3[k]=arr1[i];
                k++;
                i++;
            }
            else{
                arr3[k]=arr2[j];
                k++;
                j++;
            }
        }
        while( i<n){
            arr3[k]=arr1[i];
            k++;
            i++;
        }
        while( j<m){
            arr3[k]=arr2[j];
            k++;
            j++;


        
        
    }}

void print( int arr[], int size){
    for ( int i=0; i<=size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr1[5]={ 1,5,7,4,8};
    int arr2[3]={ 2,3,6,};
    int arr3[8]={0};
    merge(arr1,5,arr2,3,arr3);
    print(arr3,8);

} 