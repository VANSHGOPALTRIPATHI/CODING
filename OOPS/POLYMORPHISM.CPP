/* POLYMORPHISM--> IT MEANS EXISTING IN MANY FORMS 

IT HAS TWO TYPES-->
1--> COMPILE TIME POLYMORPHISM( STATIC POLYMORPHISM)
------> FUNCTION OVERLOADING --> SAME NAME OF DIFFRENT FUNCTION IS TERMED AS FUNCTION OVERLOADING
         FOR NO PROBLEM JUST CHNAGE THE ARGUMENT OF THE FUNCTION ..
------> OPERATOR OVERLOADING--> WE CAN CHANGE THE FUNCTION OF ANY OPERATOR AS + CAN DO SUBSTRACTION OR CAN PRINT HELLO ETC..
        SYNTAX-->RETURNTYPE OPERATOR + (INPUT ARGUMENT){ }

2--> RUN TIME POLYMORPHISM( DYNAMIC POLYMORPHISM)-->IS IS KNOWN AS FUNCTION OVERRIDING AS IMPLEMENTING A SAME FUNCTION WITH ANOTHER DESIRE;
RULES--> 1-> FUNCTION NAME MUST BE SAME 
        2-> ARGUMENT / PARAMETER MUST BE SAME 
        3-> ONLY DONE BY INHERITENCE 

*/
#include<iostream> 
using namespace std;

class human {

    public:
    int a;
    int b;

    void sayhello(){
        cout<<" hello is am vansh"<<endl;
    }

    void operator + ( human &obj){  // operator overloading
        int value1=this->a;
        int value2= obj.a;
        cout<<" output is "<< value1-value2<<endl;

    }

    void sayhello( string name ){  // here you can pass a string to make function diffrent and identificable
      cout<<" hello my name is "<< name << endl;

    }
};

// RUNTIME POLYMORPHISM;

 class animal{

    public:
    void speaking( ){
        cout<<" speaking"<<endl;
    }

 };

 class dog : public animal{
    public:
    void speaking(){
        cout<<" barking "<< endl;
    }

 };

int main(){
    human vansh;
    human obj1,obj2;
    obj1.a=6;
    obj2.a=5;

    vansh.sayhello("manish");
    vansh.sayhello();

    // calling + operator 

    obj1 + obj2; // SO WE CAN SEE THAT OUTPUT IS 1 SO + OPERATOR HAS PERFORMED SUBSTRACTION


    dog shera;
    shera.speaking(); // here dog speaking fn will be called this is run time polymorphism output ->> barking..

}