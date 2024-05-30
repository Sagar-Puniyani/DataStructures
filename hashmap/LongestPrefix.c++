#include <iostream>
#include <vector>
using namespace std;

class trieNode
{
public:
    char data;
    trieNode* children[26];
    bool isTerminated;
    int childNodeCount = 0;

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
            root->childNodeCount++;
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

        
        int index = word[0] - 'a';
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

    bool deleteUtil(trieNode* root , string word){
        if ( word.length() == 0 ){
            if (root->isTerminated){
            cout << "Reach at the end word" << endl;
                root->isTerminated = false;

                for ( int i=0; i<26; i++){
                    if (root->children[i] != NULL){
                        cout << "has further child " << endl;
                        return false;
                    }
                }
                return true;
            }
            return false;
        }

        int index = word[0] - 'a';
        trieNode* child = root->children[index];
        cout << child->data <<" at " << index <<  endl;

        if (child == NULL) {
            return false; // Word not found
        }

        bool shouldDeleteChild = deleteUtil(child, word.substr(1));

        if (shouldDeleteChild){
            cout << "Should Delete Block "<< endl;
            delete child;
            root->children[index] = NULL;

            if (!root->isTerminated){
                for (int i=0; i<26; i++){
                    if (!(root->data == '\0') && root->children[i] != NULL ){
                        auto data = (root->data == '\0') ? "NULL" : &root->data;
                        cout << "has further child : " << data  << endl;
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
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

    bool DeleteWord(string word){
        cout << "Search for Deleting " << endl;
        return deleteUtil(root, word);
    }

    void lcp(string word , string &ans){
        for (int i=0; i<word.length(); i++){

            char ch = word[i];

            if (root->childNodeCount == 1){
                ans.push_back(ch);

                int index = word[i] - 'a';
                root = root->children[index];
            }
            else {
                break;
            }

            if (root->isTerminated)
                break;
        }
    }
};



string longestCommonPrefix(vector<string> &arr, int n){

    string ans = "";
    for(int i=0; i<arr[0].length() ; i++){
        char ch = arr[0][i];
        cout << "ch : " << ch << endl;
        bool flag = true;

        for ( int j=1 ; j<n ; j++){
            cout << "ch = " << ch << " != " << " arr[j][i] = " << arr[j][i] << " : " << (ch != arr[j][i]) << endl; 
            if( arr[j].size() < i ||  ch != arr[j][i]){
                flag =  false;
                break;
            }
        }

        if (flag)
            ans.push_back(ch);
        else
            break;
    }

    return ans;

}



string longestCommonPrefixTrie(vector<string> &arr, int n)
{
    Trie *t = new Trie();
    for (int i=0; i<arr.size(); i++ ){
        t->insertWord(arr[i]);
    }

    string ans;
    t->lcp(arr[0],ans);
    return ans;
}







int main(){

    vector<string> arr = {"coding", "codezen", "codingninja", "coders"};
    int n = 4;

    string ans = longestCommonPrefix(arr , n);
    cout << "Longest common prefix : " << ans << endl;

    string ans1 = longestCommonPrefixTrie(arr , n);
    cout << "Longest common prefix Trie : " << ans1 << endl;
    return 0;
}