#include<iostream>
using namespace std;
#include<string>
int main(){
    char ch[10];
    cout<<" enter your name"<<endl;
    cin>>ch;
    int count=0;
    for ( int i=0;ch[i]!='\0';i++){
    
            count++;
        }
    
    cout<<" the length is "<<count<<endl;

}