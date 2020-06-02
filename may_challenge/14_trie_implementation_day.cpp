/*

Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.

*/

//solution

class TrieNode {
    public:
        bool isEnd = false;
        TrieNode *children[26]{}; //initializing children with null        
};

class Trie {
    
    TrieNode *root; //declaraing root
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        for(char c : word)
        {
            int index = c - 97;
            if(node->children[index] == NULL){             
                node->children[index] = new TrieNode();    
            }
            node = node->children[index];               
            
        }
        node->isEnd = true; //mark end
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = root;
        for(char c : word)
        {
            int index = c - 97;
            if(node->children[index]!=NULL){
                node = node->children[index];
                continue;
            }
            return 0;
        }
        if(node->isEnd == true){
            return 1;
        }
        return 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(char c : prefix)
        {
            int index = c - 97;
            if(node->children[index]!=NULL){
                node = node->children[index];
                continue;
            }
            return 0;
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */