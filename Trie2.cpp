#include <bits/stdc++.h>
// Single Node in the Prefix Tree / Trie data structure
class Node {

private:
    Node* links[26];
    int cntPrefix = 0; // counting starting with prefix words
    int cntEndWith = 0; // counting the equal words
public:
    bool containsKey(char ch) {
        return (this->links[ch - 'a'] != NULL);
    }
    void createKey(char ch) {
        this->links[ch - 'a'] = new Node();
    }
    Node* getKey(char ch) {
        return this->links[ch - 'a'];
    }
    void incPrefix() {
        this->cntPrefix++;
    }
    void incEnd() {
        this->cntEndWith++;
    }
    void decPrefix() {
        this->cntPrefix--;
    }
    void decEnd() {
        this->cntEndWith--;
    }

    int countEndingWords() {
        return this->cntEndWith;
    }
    int countStartingWords() {
        return this->cntPrefix;
    }

};

// Trie / Prefix tree
class Trie{

private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string &word){
        
        int n = word.size();
        Node *node = root;

        for (int i=0; i<n; i++) {
            char ch = word[i];

            if (!node->containsKey(ch)) {
                node->createKey(ch);
            }
            node = node->getKey(ch);
            node->incPrefix();
        }

        node->incEnd();

    }

    int countWordsEqualTo(string &word){

        int n = word.size();
        Node *node = root;

        for (int i=0; i<n; i++) {
            char ch = word[i];

            if (!node->containsKey(ch)) {
                return 0;
            }
            node = node->getKey(ch);
        }

        int cnt = node->countEndingWords();
        return cnt;

    }

    int countWordsStartingWith(string &word){

        int n = word.size();
        Node *node = root;

        for (int i=0; i<n; i++) {
            char ch = word[i];

            if (!node->containsKey(ch)) {
                return 0;
            }
            node = node->getKey(ch);
        }

        int cnt = node->countStartingWords();
        return cnt;

    }

    void erase(string &word){

        int n = word.size();
        Node *node = root;

        for (int i=0; i<n; i++) {
            char ch = word[i];

            node = node->getKey(ch);
            node->decPrefix();
        }

        node->decEnd();

    }
};
