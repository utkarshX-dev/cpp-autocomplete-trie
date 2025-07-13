#include <iostream>
using namespace std;

class TrieNode {
private:
    TrieNode* links[26];
    bool isEnd;

public:
    TrieNode() : isEnd(false) {
        for (int i = 0; i < 26; ++i)
            links[i] = nullptr;
    }

    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            delete links[i];
        }
    }

    bool containsKey(char ch) const {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }

    TrieNode* get(char ch) const {
        return links[ch - 'a'];
    }

    void setEnd() {
        isEnd = true;
    }

    bool isEndWord() const {
        return isEnd;
    }
};