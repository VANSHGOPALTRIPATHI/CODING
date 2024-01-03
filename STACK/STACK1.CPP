#include<iostream>
#include<stack>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    Stack(int size){
        this->size=size;
        arr= new int [size];
        top=-1;
    
    }

    void push( int element){
        if (size-top>1){
            top++;
            arr[top]=element;
        }
        else {
            cout<<"stack overflow"<<endl;
        }

    }
    void pop(){
        if (top>=0){
            top--;
        }
        else {
            cout<<" stack underflow";
        }
    }
    int peek() {
        if (top>=0 && top<=size){
        return  arr[top];
    }
    else {
        cout<<" stack is empty"<<endl;
        return -1;
    }

    }
    
    bool isempty(){
        if (top==-1){
            return true;
        }
        else return false;

    }




};









int main(){
    // STACK CREATION->
    /*stack<int>s;
    s.push(5);
    s.push(10);
    s.pop();
    if (s.empty()){
        cout<<" stack is empty"<<endl;

    }
    else {
        cout<<" stack is not empty"<<endl;
    }
    s.top();*/

    Stack s1(3);
    s1.push(22);
    s1.push(23);
    s1.push(24);
    s1.pop();
    cout<<s1.peek();

}