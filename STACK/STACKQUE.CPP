// Q1-> REVERSE A STRING USING STACK
// Q2-> REMOVE THE MIDDLE ELEMENT; 
#include<iostream>
using namespace std;
#include<stack>
int main(){
    string str= "vansh";
    stack<char>s;
    for (int i=0; i<=str.length();i++){
        char ch = str[i];
        s.push(ch);
    }                             // stack has this property that element inserted when printed are in reversed order
    string ans ="";
    while(!s.empty()){
        char ch =s.top();
        ans.push_back(ch);
        s.pop();
    }
    cout<<" the reversed string is "<<ans<<endl;
    return 0;
}
void solve (stack<int>&inputStack,int count, int size){ // from here 2 nd question start
if (count==size/2){
   inputStack.pop();
   return;
}
  int num= inputStack.top();
  inputStack.pop();
  solve( inputStack,count+1,size);

 inputStack.push(num);

}

void deleteMiddle(stack<int>&inputStack, int N){
	
   int count=0;                     // it is  main part starting
   solve (inputStack,count,N);
   
}
// Q3-> INSERT AN ELEMENT IN BOTTOM OF THE STACK;
void bottom( stack<int>s,int x){
if(s.empty()){
    s.push(x);
    return ;
}
else{

    int popped= s.top();
    s.pop();
    bottom ( s,x);
    s.push(popped);

}}
stack<int> pushbottom(stack<int>Stack, int x){
    bottom (Stack,x);
    return Stack;

}
void reverseStack(stack<int> &stack) {      // Q4->REVERSE THE STACK USING RECURSION;
    if (stack.empty()){
        return ;
    }
    int num = stack.top();
    stack.pop();
    //recursive call
    reverseStack(stack);
    bottom( stack,num);
}