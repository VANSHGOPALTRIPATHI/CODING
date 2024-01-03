#include<iostream>
 using namespace std;
 

  class heap {
    public:
    int arr[100];
    int size; 
     heap(){
        arr[0]=-1;
        size=0;
     }
     public:
    void print(){
    for (int i=1 ; i<=size ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
  }

  };
  // heapify algorith just places the ith index at its correct position within a tree;
  // this is for max heap->
   void heapify( int arr[], int i , int n){    // HEAPIFY ALGORITHM
        int largest=i;
        int left=2*i;
        int right=2*i+1;
        if ( left<n &&  arr[largest]<arr[left]){
            largest=left; 
        }
         if ( right<n &&  arr[largest]<arr[right]){
            largest=right;
        }

        if (largest!=i){

            swap(arr[largest],arr[i]);
            heapify(arr,largest,n);
        }
     }
     // this is for min heap->
     /* void heapify( int arr[], int i , int n){    // HEAPIFY ALGORITHM
        int smallest=i;
        int left=2*i;  //{ we are following here 1 based indexing};
        int right=2*i+1;
        if ( left<=n &&  arr[smallest]>arr[left]){
            smallest=left; 
        }
         if ( right<=n &&  arr[smallest]>arr[right]){
            smallest=right;
        }

        if (smallest!=i){

            swap(arr[smallest],arr[i]);
            heapify(arr,smallest,n);
        }
     }*/
     // HEAP SORT ALGORITHM-> 
      void heapsort( int arr[], int n){   // this is heaping sorting
        int size=n;
        while ( size>1){
            swap(arr[size],arr[1]);
            size--;
        
        heapify(arr,1,size); // completed 
        }
      }
 

   int main( ){

    heap h1;
    int arr[6]={ -1, 54,53,55,52,50};
    int n=5;
    // HEAP CREATION->;;
    for( int i=n/2; i>0 ;i--){
        heapify(arr,i,n);
    }
    cout<<" printing the array now "<<endl;
    for ( int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapsort(arr,n);
    h1.print();
    return 0;
   }



   