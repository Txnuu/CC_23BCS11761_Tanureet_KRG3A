#include <iostream>
using namespace std;

class Node {
public:
    Node* links[26];
    bool flag = false;

    bool containKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }

    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (int i = 0; i < word.length(); i++) {
            if (!node->containKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;

        for (int i = 0; i < word.length(); i++) {
            if (!node->containKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }

        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;

        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }

        return true;
    }
};

int main() {
    Trie* obj = new Trie();

    obj->insert("apple");

    cout << obj->search("apple") << endl;      // 1
    cout << obj->search("app") << endl;        // 0
    cout << obj->startsWith("app") << endl;    // 1

    obj->insert("app");

    cout << obj->search("app") << endl;        // 1

    return 0;
}