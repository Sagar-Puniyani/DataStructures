#include <iostream>
using namespace std;

class trieNode
{
public:
    char data;
    trieNode* children[26];
    bool isTerminated;

    trieNode(char data ){
        this->data = data;
        for( int i=0 ; i<26 ; i++){
            this->children[i] = NULL;
        }
        this->isTerminated = false; 
    }
};

class Trie{
    private:
    void insertUtil(trieNode* root  ,string  word){
        // base case 
        if (word.length() == 0){
            root->isTerminated = true;
            cout << "Inserted At Terminal" << endl;
            return;
        }

        int index = word[0] - 'A';
        cout << "Index Insertion : " << index<< endl;
        trieNode* child;

        if (root->children[index] != NULL ){
            // present
            child = root->children[index];
        }
        else {
            // absent 
            child = new trieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child , word.substr(1));
    }

    bool searchUtil(trieNode* root , string word){
        // base case 
        if ( word.length() == 0 ){
            cout << "Found " << endl;
            return root->isTerminated;
        }

        
        int index = word[0] - 'A';
        cout << "Index = " << index << endl;
        trieNode* child;

        if (root->children[index] != NULL ){
            // present
            child = root->children[index];
        }
        else {
            // absent 
            return false;
        }

        // recursion
        return searchUtil(child , word.substr(1));
    }

    

    public:
    trieNode* root;

    Trie(){
        root = new trieNode('\0');
    }

    void insertWord(string word){
        insertUtil(root , word);
        cout << "Inserted" << endl;
    }

    bool  searchWord(string word){
        cout << "Searching " << endl;
        return searchUtil(root , word);
    }


};


int main(){
    Trie* t = new Trie();

    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");

    cout << "word present or not : " << t->searchWord("TIM") << endl;
    cout << "word present or not : " << t->searchWord("TIME") << endl;
    cout << "word present or not : " << t->searchWord("ARM") << endl;

    return 0;
}