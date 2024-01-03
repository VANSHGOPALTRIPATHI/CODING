#include<iostream> 
using namespace std;


        /*             TRIE
        WHY TRIE-> SUPPOSE IN A DICTIONARY WE WANT TO STORE SOME WORDS SEARCH FOR WORDS AND REMOVE A WORD 
        SO WHCH DATA STRUCTURE CAN WE USE YOU MIGHT SAY THAT WE CA USE HASMAP AS IT HAS LINEAR TIME COMPLEXITIES
        BUT IN A AVERAGE CASE ONLY IN WORST CASE THE COMPLEXITIES MAY VARY SO WE WILL USE TRIE.
        
        WHAT IS A TRIE-> IT IS A DATA STRUCTURE JUST SIMILAR AS A TREE WHICH HAS SOME ROOT AND CHILD NODE 

        INSERTION-> IF WE HAVE TO ADDD A WORD THEN FIRST LETTER IS SERACHED IN ROOT NODE IF THE LETTER IS PRESENT 
        THEN MOVE AHEAD AND IF NOT PRESENT THEN CREATE NEW NODE AND ADD THAT LETTER NEXT TO IT.
        
        */ 

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
        int index= word[0]-'A';
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
    //-----------------------------------------------------------------------------------
    // SEARCHING ->
    bool searchuntil(trienode* root, string word){
         // base case ->
        if ( word.length()==0){
            return root->isterminal;
            
        }
        // asumption first letter is in caps->
        int index= word[0]-'A';
        trienode* child;
        if (root->children[index]!=NULL){
            //present
            child=root->children[index];
        }
        else{
            //absent
            return false;
        }
        // recursion->
        insertuntil(child,word.substr(1));  // word 1 letter ko chodh ke
    }

    bool searchword( string word){
        return searchuntil(root, word);
    }
    //-------------------------------------------------------------------------------------------------
      // REMOVING A WORD->

     bool removeuntil(trienode* root, string word){
        searchword(word);
        if (word.length()==0){
            return root->isterminal=false;
        }
        else{
            return false ;
        }

     }


     bool removeword( string word){
        return removeuntil(root,word);
     }
     //---------------------------------------------------------------------------------------------------------




};
int main(){
    trie *t= new trie();
    t->insertword("VANSH");
    t->insertword("ARM");
    t->insertword("TIMER");
    cout<<"present or not"<<t->searchword("TIM")<<endl;
    t->removeword("VANSH");
    cout<<"present or not"<<t->searchword("VANSH")<<endl;


}