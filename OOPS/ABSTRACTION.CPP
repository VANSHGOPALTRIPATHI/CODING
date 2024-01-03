#include<iostream>
using namespace std;


/* ABSTRACTION--> IT IS IMPLEMENTATION HINDIG SHOWS ONLY THE MAIN THING AND THE PR0CESS IS HIDED 
Data abstraction is one of the most essential and important features of object-oriented programming in C++. 
Abstraction means displaying only essential information and hiding the details. 
Data abstraction refers to providing only necessary information about the outside world’s data, 
hiding the background details or implementation.

Advantages Of Abstraction
-->Only you can make changes to your data or function, and no one else can.
-->It makes the application secure by not allowing anyone else to see the background details.
-->Increases the reusability of the code.
-->Avoids duplication of your code.

 
        
*/
class abstraction {
    private:
        int a, b;
    public:
        // method to set values of private members 
        void set(int x, int y) {
            a = x;
            b = y;
        }
    void display() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};
int main() {
    abstraction obj;
    obj.set(10, 20);
    obj.display();
    return 0;
}
