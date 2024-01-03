#include<iostream>
using namespace std ;

    bool binarysearch( int arr[] , int start,int end,int key){
            int mid = start+ ( end -start)/2;
            if ( arr[mid ]=key){
                return true;
            }
            if( start>end){
                    return false;
                }
                if ( arr[mid <key]){
                    return binarysearch(arr,mid +1, end , 10);
                }
                else 
                return binarysearch( arr, start,mid -1 , 10);
                
            }

        

    
int main(){
    int arr[5]={  3,5,6,7,8};
   int ans = binarysearch( arr,0,4,10);
   cout<< endl<<endl<<endl<<"present or not 1 for yes and 0 for no so the answeer is  "  <<ans <<  endl<<endl<<endl<<endl<<endl<<endl<<endl;

}