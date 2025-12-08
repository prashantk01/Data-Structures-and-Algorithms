// Trie is also known as digital tree or prefix tree
// It is a tree data structure used to efficiently store and retrieve keys in a dataset of strings
// each node represnt single charcter of a string
// commonly used for autocomplete and spell checking
// common operations are insert, search and delete

#include<iostream>
using namespace std;
struct Node {
    Node* children[26] = {nullptr};// a-z
    int countEndWith = 0; // count of words ending at this node
    int countPrefix = 0; // count of words having this prefix

    bool doesItContainChild(char ch){
        return children[ch - 'a'] != nullptr;
    }

    void addChild(char ch, Node* newNode){
        children[ch-'a'] = newNode;
    }

    Node* getChild(char ch){ 
        return children[ch-'a'];
    }

    void increaseEndWith(){
        countEndWith++;
    }

    void increasePrefix(){
        countPrefix++;
    }

    void decreaseEndWith(){
        countEndWith--;
    }

    void decreasePrefix(){
        countPrefix--;
    }

    int getEndWith(){
        return countEndWith;
    }

    int getPrefix(){
        return countPrefix;
    }
};

class Trie{
    private:
        Node* root;
    public:
    Trie(){
        root = new Node();
    }
    ~Trie() {
        deleteNode(root);
    }
    void deleteNode(Node* node) {
        if(!node) return;
        for(int i = 0; i < 26; i++) {
            if(node->children[i]) deleteNode(node->children[i]);
        }
        delete node;
    }

    void insert(string word) {
        int size = word.size();
        char ch;
        Node* node = root;
        for(int i=0; i<size; i++){
            ch = word[i];
            if(!node->doesItContainChild(ch)){
                Node* newNode = new Node();
                node->addChild(ch, newNode);
            }
            node = node->getChild(ch);
            node->increasePrefix();
        }
        node->increaseEndWith();
    }

    int countWordsEqualTo(string word) {
        int size = word.size();
        char ch;
        Node* node = root;
        for(int i=0; i<size; i++){
            ch = word[i];
            if(!node->doesItContainChild(ch)){
                return 0;
            }
            node = node->getChild(ch);
        }
        return node->getEndWith();
    }

    int countWordsStartingWith(string word) {
        int size = word.size();
        char ch;
        Node* node = root;
        for(int i=0; i<size; i++){
            ch = word[i];
            if(!node->doesItContainChild(ch)){
                return 0;
            }
            node = node->getChild(ch);
        }
        return node->getPrefix();
    }

    void erase(string word) { // assuming word already exist
        int size = word.size();
        char ch;
        Node* node = root;
        for(int i=0; i<size; i++){
            ch = word[i];
            if(!node->doesItContainChild(ch)){
                return;
            }
            node = node->getChild(ch);
            node->decreasePrefix();
        }
        node->decreaseEndWith();
    }
};

int main(){
    return 0;
}
