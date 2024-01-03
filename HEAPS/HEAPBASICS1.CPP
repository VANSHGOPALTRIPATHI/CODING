/*                         HEAP
HEAP->IT IS A DATA STRUCTURE WITH A COMPLETE BINARY TREE THAT COMES WITH A HEAP ORDER PROPERTY 
HEAPS ARE GENERALLY ARE OF TW0  TYPES 
->MAX HEAP
->MIN HEAP
COMPLETE BINARY TREE ->EVERY LEVEL COMPETELY FILLED EXEPT THE LAST LEVEL AND THE NODES ALWAYS ADED FROM THE LAST LEVEL FROM THE LEFT SIDE IS A COMPLETE BINRY TREE                                
MAX HEAP-> THE CHILD ELEMENTS ARE ALWAYS SMALLER THAN THE PARENT NODE
MIN HEAP-> THE PARENT NODES ARE SAMLLLER THAN THE CHILD ELEMENT  
------> IN MAX HEAP->>
  IF NODE IS IN iTH INDEX  THEN THE LEFT CHILD WILL BE AT (2*i)INDEX AND RIGHT CHILD WLL BE AT (2*i)+1 INDEX   
  -> AND PARENT IS GUVEN BY (i/2) INDEX ;                               */

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

    void insertion ( int value ){      //(time complexity->o(logn))
        size=size+1;
        int index= size ;
        arr[index]=value;
        while ( index>1){
           int parent =index/2;
            if ( arr[parent]<arr[index]){
                swap ( arr[parent],arr[index]);
                index=parent;

            }
            else{
                return ;
            }
        }
    }
    void print( ){
    for (int i=1 ; i<=size ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
  }

  void deletefromheap(){      // deletion in a heap
    if ( size==0){
        cout<<" nothing to delete"<<endl;
        return ;
    }
    // step->1 put last element in root eleemenet->
    arr[1]=arr[size];
    // step->2-> remove last element
    size --;
    int i=1;
    while(i<size)
    {
        int leftindex= 2*1;
        int rightindex=(2*i)+1;
        if ( leftindex<size && (arr[i]<arr[leftindex])){
            swap(arr[i],arr[leftindex]);
            i=leftindex;
        }
        else if (rightindex<size && (arr[i]<arr[rightindex])){
             swap(arr[i],arr[rightindex]);
              i=rightindex;
        }
        else {
            return ;
        }
    }
    

  }

  };
   int main( ){

    heap h1;
    h1.insertion(50);
    h1.insertion(55);
    h1.insertion(53);
    h1.insertion(52);
    h1.insertion(54);
    h1.print();
    h1.deletefromheap();
    h1.print();


    return 0;
   }