#include <iostream>
#include <vector>
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

        int index = word[0] - 'a';
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


    public:
    trieNode* root;

    Trie(){
        root = new trieNode('\0');
    }

    void insertWord(string word){
        insertUtil(root , word);
        cout << "Inserted" << endl;
    }

    void printSuggestions(trieNode* curr , vector<string> &temp ,string prefix){
        if (curr->isTerminated){
            temp.push_back(prefix);
        }

        for (char ch='a'; ch<='z'; ch++){
            trieNode* next = curr->children[ch - 'a'];

            if ( next != NULL ){
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }

    }

    vector <vector <string>> getSuggestion(string str ){
        trieNode* prev = root;
        vector <vector<string>> output;
        string prefix = "";

        for( int i=0; i<str.length(); i++){
            char lastchar = str[i];

            prefix.push_back(lastchar);

            // check lastchar 
            trieNode* curr = prev->children[lastchar - 'a'];

            // if not found
            if (curr == NULL ){
                break;
            }
            
            vector <string > temp;
            printSuggestions(curr , temp , prefix);
            
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }

        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr){
    // create the Trie
    Trie* t = new Trie();

    // Insert contact in Trie
    for (int i=0; i<contactList.size(); i++){
        string str = contactList[i];
        t->insertWord(str);
    }

    return t->getSuggestion(queryStr);


}

int main(){
    vector<string> contactList = {"cod", "coding", "codding", "code", "coly"};
    string querstr = "coding";

    vector<vector<string>> ans  = phoneDirectory(contactList, querstr);

    cout << "Print Contacts" << endl;
    for (auto container : ans ) {
        for ( auto word : container ){
            cout << word << " ";
        }
        cout << endl;
    }


    return 0;
}