#include<iostream>
using namespace std;

     bool issorted( int arr[],int size ){
        if ( size ==0  ){
            return true ;
        }
        else if ( size ==1 ){
             return true ;
        }
        else if( arr[0]>arr[1]){
            return false ;
        }
        else {
            bool ans = issorted( arr+ 1, size -1);
            return ans ;
        }
    
     }


int main(){ 
    
   int arr[10]={   1,3,5,8,9,10,46,47,48,50};
    bool ans =issorted( arr,10);
    if ( ans ){
        cout<< " array is sorted ";
    }
    else cout<<" array is not sorted";
}