class Node {
private:
    Node* links[26];
    bool flag = false;

public:
    bool containsKey(char ch) {
        return (this->links[ch - 'a'] != NULL);
    }

    void createKey(char ch) {
        this->links[ch - 'a'] = new Node();
    }
    Node* getKey(char ch) {
        return this->links[ch-'a'];
    }
    void setEnd() {
        this->flag = true;
    }
    bool isEnd() {
        return this->flag;
    }

};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {

        Node* node = root;
        int n = word.size();

        for (int i=0; i<n; i++) {
            char ch = word[i];

            if (!node->containsKey(ch)) {
                node->createKey(ch);
            }
            node = node->getKey(ch);

        }
        node->setEnd();
        
    }
    
    bool search(string word) {
        Node* node = root;
        int n = word.size();

        for (int i=0; i<n; i++) {
            char ch = word[i];

            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->getKey(ch);

        }
        
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        int n = prefix.size();

        for (int i=0; i<n; i++) {
            char ch = prefix[i];

            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->getKey(ch);

        }
        
        return true;
    }
};
