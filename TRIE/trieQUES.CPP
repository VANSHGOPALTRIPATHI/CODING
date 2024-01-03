#include<iostream>
using namespace std;
#include<vector>



// Q1-> LONGEST COMMON PREFIX

// APPROACH 1 -> WITHOUT TRIE O(M*N)

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans="";
    for ( int i=0 ; i< arr[0].size();i++){
        char ch= arr[0][i];
        bool match = true;

        for ( int j=0 ;j< n; j++){
          if (arr[j].length() < i || ch != arr[j][i]) {
            match = false;
            break;
          }
        }
            if (match==false){
                break;
            }
            else{
                ans.push_back(ch);
            }
    }
    return ans ;
}
//--------------------------------------------------------------------------------------


// APPROACH 2-> WITH TRIE->  1st approach is better than 2nd but we are studying trie thsts why we have used it 
class trienode{
    public:
    char data;
    trienode* children[26];
    bool isterminal;

    trienode( char ch)
{
    data=ch;
    for ( int i=0; i<26 ;i++){
        children[i]=NULL;
    }
    isterminal=false;
}


};
class trie{
    public:
    trienode* root;
    
    trie( char ch){
        root=new trienode(ch);
    }
    
     void insertuntil(trienode*root, string word){
        // base case ->
        if ( word.length()==0){
            root->isterminal=true;
            return;
        }
        // asumption first letter is in caps->
        int index= word[0]-'a';
        trienode* child;
        if (root->children[index]!=NULL){
            //present
            child=root->children[index];
        }
        else{
            //absent
            child=new trienode(word[0]);
            root->children[index]=child;
        }
        // recursion->
        insertuntil(child,word.substr(1));  // word 1 letter ko chodh ke

    }
    void insertword( string word ){
        insertuntil( root,word);
    }
    

    void LCP (  string str, string &ans){
            for (int i=0 ;i<str.length();i++){
                char ch= str[i];

                if (root->child==1){
                    ans.push_back(ch);
                    // aage badh jap
                    int index=ch-'a';
                    root=root->children[index];
                }
                else{
                    break;
                }
                if (root->isterminal){
                    break;
                }
            }
   
                }
};



string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here

    trie*t=new trie('/0');
    for (int i=0; i<=n ;i++){
       t->insertword(arr[i]);
    }
    string first= arr[0];
    string ans ="";

    t->LCP(first,ans);
    return ans;

}


