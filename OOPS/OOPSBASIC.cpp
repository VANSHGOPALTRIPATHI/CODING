#include<iostream>
using namespace std;

class hero {

    public:  // there are three types of modifiers public ,private , and protective 
    int health;
    char level;

};
int main(){
    
    hero vansh ;
    

        vansh.health=70;
        vansh.level='A';

   
    cout<< endl<<endl<<" health of vansh is "<< vansh.health<<endl<<endl;  
     cout<< endl<<endl<<" level of vansh is "<< vansh.level<<endl<<endl;
    // an empyty class takes the 1 byte storage memory in the system

}