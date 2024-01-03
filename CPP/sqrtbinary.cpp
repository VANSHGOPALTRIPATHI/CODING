#include <iostream>
using namespace std;
int squareroot( int num){
    int answer=0;
    int start=0;
    int end=num;
    int mid= start+( end-start)/2;
    while(start<end){
        if ( (mid*mid)==num){
            return mid;
        }
        else if ((mid*mid)< num){
            mid = answer;
            start=mid+1;
        }
        else {
            end=mid-1;

        }
        mid= start+( end-start)/2;
        

    }   
        return answer;
    }
int main(){
    
    
    cout<<"the answer is "<<squareroot(36)<<endl;
    
}
