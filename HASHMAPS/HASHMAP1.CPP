#include <iostream>
#include <map>
#include <unordered_map>
#include<vector>
using namespace std;

int main()
{

    // creation->
    unordered_map<string, int> m;

    // INSERTION->
    // HAR EK KEY KE CORRESPONDING EK HI VALUE HOGI ->>

    // 1st ->
    pair<string, int> pair1 = make_pair("vansh", 1);
    m.insert(pair1);

    // 2nd way->
    pair<string, int> pair2("gopal", 2);
    m.insert(pair2);

    // 3->
    //  here creation happens ->
    m["tripathi"] = 3;
    // if let suppose again i do the same thing that the again i ->
    m["tripathi"] = 4; // here updation happens means <tripathi,4> will happen

    // search
    cout << m["vansh"] << endl;    // by using this type if the key is not present it will give 0 and make it corresponding to 0
    cout << m.at("gopal") << endl; // by using "at" is a key is nit present it will give an error
    cout<<m.size()<<endl;

     // to check presence ->
     cout<<m.count("bro")<<endl;  // if key is absent gives 0;
     cout<<m.count("vansh")<<endl;   // if present gives 1;

     // erase->
     m.erase("gopal");
     cout<<m.size()<<endl;

    //1->  traversing-->
     for (auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
     }
    //2-> itertaive way->
    unordered_map<string,int>:: iterator it=m.begin();
        while( it !=m.end()){
            cout<<it->first<<" "<<it->second<<endl;
            it++;
        }

     }   // question-->

//-------------------------------------------------------------------------------------------------------------
        int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here
    unordered_map<int,int> count;
    int  maxifreq=0;
    int  maxans=0;

    for (int i=0 ;i < arr.size() ;i++){
        count[arr[i]]++;
        maxifreq=max(maxifreq,count[arr[i]]);
    }
    for (int i=0 ; i<arr.size();i++){
        if (maxifreq==count[arr[i]]){
            maxans=arr[i];
            break;
        }
    }
    return maxans;

}
//--------------------------------------------------------------------------------------------------------------

// BUCKET ARRAY->>

/*(data structure) Definition: Implementation of a dictionary by an array indexed by the keys of the items in the dictionary.   jaise vansh ko array me store karana h to kaise karayenge ->
this can be done using two methods->

1-> HASH CODE

2->COMPRESSSION FUNCTION

***HASH CODE ->IT PROVIDES BASICALLY A VALUE IN FORM OF INT TO A STRING FOR EN VANSH->22 IT CAN BE ANY VALUE

***COMPRESSION FUNCTION->IT GIVES THE MODULUS OF THAT VALUE BY SOME NUMBER FOR EX-> (HASHCODE VALUE % N ) 
AND THEN MAP IT WITH INDEX OF THAT ARRAY ; 
            SOME TIMES THE COLLISON HAPPENS IN HASCODE->
-->There are dozens of different ways to handle collisions in hash maps depending on what system you're using. Here are a few:

-->If you use CLOSED ADRESSING, then you probably would have each item hash to a linked list of values, all of which have the same hash code, and would then traverse the list looking for the element in question.

If you use LINEAR PROBING  ( F(i)=i), then following a hash collision you would start looking at adjacent buckets until you found the element you were looking for or an empty spot.

If you use QUADRATIC PROBING ( F(i)=i SQUARE), then following a hash collision you would look at the elements 1, 3, 6, 10, 15, ..., n(n+1)/2, ... away from the collision point in search of an empty spot or the element in question.

If you use CUCKOO HASHING, you would maintain two hash tables, then displace the element that you collided with into the other table, repeating this process until the collisions resolved or you had to rehash.
If you use dynamic perfect hashing, you would build up a perfect hash table from all elements sharing that hash code.

The particular implementation you pick is up to you. Go with whatever is simplest. I personally find chained hashing (closed addressing) the easiest, if that suggestion helps.           */

//-----------------------------------------------------------------------------------------------------------


// BEST PART OF HASH MAPS ->

// COMPLEXITIES ->  ARE NEARY TO BE BIG O(1); LINEAR
// putting element while colliosn in same place happen in linekd list form and its size is n/b->n= size of array
// b=element to be linked so n/b <=0.7 and hence the complexity is linear;

     

