#include<iostream>
 using namespace std;
 #include<queue>
 

  class heap {
    public:
    int arr[100];
    int size; 
     heap(){
        arr[0]=-1;
        size=0;
     }
  };

  int main(){
    // using stl priority queue->>
    //default ->max heap;
    //max heap->
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);
    cout<<" element at the top"<<" "<<pq.top()<<endl;
    pq.pop();
    cout<<" element at the top"<<" "<<pq.top()<<endl;
    //min heap->
    priority_queue<int,vector<int>,greater<int> > minheap;
    minheap.push(10);
    minheap.push(20);
    minheap.push(30);
    minheap.push(40);
    minheap.push(50);
    cout<<" element at the top"<<" "<<minheap.top()<<endl;


  }