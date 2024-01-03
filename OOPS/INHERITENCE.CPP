#include<iostream>
using namespace std;

// INHERITENCE  --> taking  property  from anoother class into some other class is known as inheritence 
// PARENT / SUPER CLASS --> MAIN FROM FROM WHICH THE PROPERTIES HAVE BENN TAKEN 
// CHILD / SUB CLASS -->  TO WHICH THE PROPERTIES HAVE BEEN GIVEN IS KNOWN AS SUB CLASS

class human{

    public:
    int height ;         /* PROTECTED --> IT IS KIND OF SAME AS PRIVATE WHICH BE
                                           ASSCESED IN ITS SAME CLASS BUT CAN ALSO
                                            BE ACCESED IN CHILED OR DERIVED CLASS*/
    string color;
    int weight;

    int getweight(){
        return weight;   /*            -->> INHERITENCE TABLE-->>
                                PUBLIC  &   PUBLIC ->> PUBLIC
                                PUBLIC  &   PRIVATE --> PRIVATE 
                                PUBLIC  &   PROTECTED--> PROTECTED
                                PROTECTED+( PUBLIC AND PROTECTED)--> PROTECTED
                                PROTECTED+ PRIVATE --> PRIVATE 
                                PRIVATE + ( ANY MODE )--->> IS NOT ACCESSIBLE  */

    }
    void setheight( int h){
        this->height=h;
    }
    string setcolor( string c){
        this->color=c;
    }

};

class male : public human{ //   BY THIS LINE MALE CLASSS INHERITS THE HUMAN CLASS;

    int age ;
     // here it is made as public so it will be public as built access anywhre

};
int main(){

    male person1;
    person1.setheight( 160);
    cout<< " height of person 1 is "<<person1.height<<endl;
    cout<< person1.color<<endl;
    person1.setcolor("Green");
    cout<< " the color of person 1  is "<< person1.color<<endl;


}

/* TYPES OF INHERITENCE -->
1--> SINGLE  ---->( A INHERITS B )IS TYPE OF SINGLE INHERITENCE 
2--> MULTI LEVEL---> ( A INHERITS B , B INHERITS C ,C INHERITS D ) IS KNOWN AS MULTI LEVEL INHERITENCE
3--> MULTIPLE --> (  A IS A CLASS AND B IS A CLASS AND C IS ANOTHER CLASS WHICH INHERITS BOTH THE CLASS I KNOWN AS MULTIPLE INHERITENCE)
4-->HEIRARICHAL --> A SINGLE CLASS IS PARENT FOR MANY CLASS EX- A IS PARENT CLASS FOR B AND C IS A TYPE OF HEIRARICHAL INHERITENCE 
5--> HYBRID -->> COMBINATION OF MORE THAN ONE TYPE OF INHERITENCE FOR EX MIX OF SINGLE + MULTIPLE ETC.
 */

/* INHERITENCE AMBIGUITY--> 
SUPPOSE THERE ARE TWO CLASS A AND B AND C INHERITS BOTH THE CLASS( A AND B) AND A HAS A FUNCTION NAMED AS FUNC(), AND B HAS 
A SAME FUNCTION NAMED FUNC(),THE IF WE CALL THE FUNCTION  THEN WHICH FUNCTION WILL CALL SO TO RESOLVE THIS WE USE THE SCOPE FUNCTION(::)

WE WILL WRITE IT AS-->> OBJECT1.A::FUNC();


*/
