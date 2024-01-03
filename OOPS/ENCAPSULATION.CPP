#include<iostream>
using namespace std;
//  ENCAPSULATION ( DATA / INFORMATION HIDING) - WRAPPING UP OF DATA MEMBERS AND FUNCTIONS 
// FULLY ENCAPSULATED CLASS = ALL DATA MEMBERS ARE PRIVATELY MARKED USED ONLY IN SAME CLASS

class student {

    private :
        string name ;
        int height; 
        int marks;

    public:

    int getmarks(){
        return this -> marks ; //    ( THIS IS KNOWN AS ENCAPSULATION  )
    }
};


