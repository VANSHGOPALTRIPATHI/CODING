#include<iostream>
using namespace std;
#include<queue>

class Queue {
     int *arr;
     int qfront;
     int rear;
     int size;
public:
    Queue() {
        // Implement the Constructor
        size=100001;
        arr=new int[size];
        qfront=0;
        rear=0;
         
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if (qfront==rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data) {
        //push
        if (rear==size){
            cout<<"queue is full"<<endl;
            }
        else{
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront==rear){
            return -1 ;
        }
        else{
            int ans= arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if (qfront == rear) {
              qfront =0;
              rear = 0;
            }

            return ans;
        }
    }

    int front() {
        if (qfront==rear){
            return -1;
        }
        else{
            return arr[qfront];
        }

        
    }
};
#include <bits/stdc++.h> 
class CircularQueue{
    public:
    // Initialize your data structure.
    int size;
    int qfront ;
    int rear;
    int *arr;
    CircularQueue(int n){
        // Write your code here.
        size=n;
        qfront=rear=-1;
        arr=new int[size];
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if (( qfront==0 && rear==size-1) ||( rear=(qfront-1)%(size-1))){
            return false;
        }
        else if ( qfront==-1){
            qfront=rear=0;
        }
        else if (rear==size-1 && qfront!=0){
            rear=0;
        }
        else {
            rear ++;
        }
        arr[rear]=value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(qfront ==-1){
            return -1;
        }
        int ans=arr[qfront];
        arr[qfront]=-1;
        if (qfront==rear){
            qfront=rear=-1;

        }
        else if (qfront==size-1){
            qfront=0;
        }
        else {
            qfront++;

        }
        return ans;
    }
};




int main(){
    queue<int>q;
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);

    cout<<q.front()<<endl;
    cout<<" the size of the queue is "<<q.size()<<endl;
    if (q.empty()){
        cout<<" queue is empty"<<endl;

    }
    else {
        cout<<" queue is not empty"<<endl;
    }
    return 0;
}