#include<iostream>
using namespace std;

class hero{

    private :

    char power;

    public :
    int health;
    static int timeTocomplete;
    

    //paremetrised constructor 
      hero ( int health, char power){
         // here we will use the this keyword
         cout<<" this value ->"<<this<<endl;
         this->health= health; // this act like a onter wich contain the adress of the object
         this-> power= power;
      }
      hero(){
         cout<<"constructor called"<<endl;
      }
      

      

    

    /* as we i can acess health anywhere ass it is 
    public but to acess power anywhere
    we can use GETTERS ANS SETTERS*/

    // GETTERS
     char getpower(){
        return power;
     }
     //SETTERS
     void setpower(char ch){
        power =ch;

     }
};
 int hero ::timeTocomplete=5; // static property of class do not depend upon object

int main(){

    hero vansh ( 70,'a');
  /* cout<<" heath  of vansh is "<<vansh.health<<endl;//easily acessed as it is public
   cout<< " power of vansh is "<< vansh.getpower()<<endl;
   vansh.setpower('A');
   cout<< " power of vansh is "<< vansh.getpower()<<endl;

   cout<<endl;

   cout<<" adress of vansh"<<&vansh<<endl;*/

    // COPY CONSTRUCTOR

    hero manish( vansh);   // this copies vansh paremeters into manish;
   cout<<"time taken to complete is " << vansh.timeTocomplete;






}
