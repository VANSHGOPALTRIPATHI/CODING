#include <iostream>
using namespace std;
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>

int main(){

    array<int,4>b={ 1,2,3,4};
    cout<<b.size()<<endl;;
    for ( int i=0;i<b.size();i++){
        cout<<b[i]<<endl;
    }
   cout<<b.front()<<endl;
   cout<<b.back();

    vector<int> a;
    cout<<a.capacity()<<endl;
    a.push_back(2);
    cout<<a.capacity()<<endl;
    a.push_back(56);
    cout<<a.capacity()<<endl;
    a.push_back(56);
    cout<<a.capacity()<<endl;
    for ( int i=0;i<a.size();i++){
        cout<<a[i]<<endl;
    }

//deque is same nearly as vector 


    stack<string> s;
    s.push(" vansh");
    s.push( "gopal");
    s.push(" triapthi");
    cout<<" top element"<<s.top()<<endl;
    s.pop();
     cout<<" top element"<<s.top()<<endl;
     cout<<s.size()<<endl;;
     cout<<s.empty();

    queue<string> k;
    k.push(" vansh");
    k.push( "gopal");
    k.push(" triapthi");
    cout<<" top element"<<k.front()<<endl;
    k.pop();
     cout<<" top element"<<k.front()<<endl;
     cout<<k.size()<<endl;;
     cout<<k.empty();


     vector<int>a;
     a.push_back(2);
     a.push_back(3);
     a.push_back(5);
     a.push_back(7);
     a.push_back(8);
     a.push_back(9);
     cout<<" the binary search in thus vecror is "<<binary_search(a.begin(),a.end(),5)<<endl;
//1->present,0->not present



}