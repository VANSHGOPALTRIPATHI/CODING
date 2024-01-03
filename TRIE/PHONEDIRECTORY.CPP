#include<iostream>
using namespace std;
#include<vector>
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
    
    trie( ){
        root=new trienode('\0');
    }
//---------------------------------------------------------------------------------------------------------
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
    void printsuggestion( trienode* curr,vector<string>&temp,string prefix){
        if (curr->isterminal){
            temp.push_back(prefix);
            
        }
        for ( char ch='a';ch<='z';ch++){
            trienode* next= curr->children[ch-'a'];

            if (next!=NULL){
                prefix.push_back(ch);
                printsuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }

    }
    void insertword( string word ){
        insertuntil( root,word);
    }
    vector<vector<string>> getsuggestion(string str){
        trienode* prev= root;
        vector<vector<string>>output;
        string prefix="";

        for ( int i=0 ;i<str.length();i++){
            char lastch=str[i];
            prefix.push_back(lastch);

        // check for last ch->
        trienode* curr= prev->children[lastch-'a'];

        // if not found ->
        if (curr == NULL) {
                break;
        }
        // if found->
        vector<string> temp;
        printsuggestion(curr, temp, prefix);

        output.push_back(temp);
        temp.clear();
        prev = curr;
        }
        return output;
    }
}; 
vector<vector<string>> phoneDirectory(vector<string> &contactList,
                                        string &queryStr) {
    //    Write your code here.
    trie * t= new trie();
    for ( int i=0 ; i<contactList.size();i++){
        string str= contactList[i];
        t->insertword(str);
    }
    return t->getsuggestion(queryStr);
}