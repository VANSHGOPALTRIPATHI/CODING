#include<iostream>
using namespace std;

    void update ( int *p){
        *p=*p+1;
    }
int main(){
         
            int i=5;
            int *ptr=&i;
            int **ptr2=&ptr;
            int ***ptr3=&ptr2;
            cout<<ptr<<endl;
            cout<<ptr2<<endl;
            cout<<*ptr<<endl;
            cout<<**ptr2<<endl;
            cout<<ptr3<<endl;
            cout<<***ptr3<<endl;
            cout<<endl<<endl<<endl;
            update (ptr);
            cout<<ptr;
}