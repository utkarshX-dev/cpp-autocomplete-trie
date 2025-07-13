#include "TrieNode.cpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Trie {
private:
    TrieNode* root;

    void dfs(TrieNode* node, string& path, vector<string>& result) {
        if (node->isEndWord())
            result.push_back(path);

        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (node->containsKey(ch)) {
                path.push_back(ch);
                dfs(node->get(ch), path, result);
                path.pop_back();
            }
        }
    }

    void freeNode(TrieNode* node) {
        if (!node) return;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (node->containsKey(ch)) {
                freeNode(node->get(ch));
            }
        }
        delete node;
    }

public:
    Trie() {
        root = new TrieNode();
    }

   
    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;

    ~Trie() {
        freeNode(root);
    }

    void insert(const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            if (!curr->containsKey(ch))
                curr->put(ch, new TrieNode());
            curr = curr->get(ch);
        }
        curr->setEnd();
    }
    bool search(const string& word) const {
    TrieNode* curr = root;
    for (char ch : word) {
        if (!curr->containsKey(ch))
            return false;
        curr = curr->get(ch);
    }
    return curr->isEndWord();
}

    vector<string> autocomplete(const string& prefix) {
        TrieNode* curr = root;
        for (char ch : prefix) {
            if (!curr->containsKey(ch)) return {};
            curr = curr->get(ch);
        }

        vector<string> result;
        string path = prefix;
        dfs(curr, path, result);
        return result;
    }
};