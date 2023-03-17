class TrieNode{
public:
    TrieNode* child[26];
    bool flag;
    
    TrieNode(){
        flag = false;
        for(int i=0;i<26;i++)
            child[i] = NULL;
    }
    
    bool check(char c){
        return (child[c-'a']!=NULL);
    }
    void put(char c,TrieNode* node){
        child[c-'a'] = node;
    }
    TrieNode* get(char c){
        return child[c-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isLast(){
        return flag;
    }
};
class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* node = root;
        for(auto &i:word){
            if(!(node->check(i))){
                node->put(i,new TrieNode());
            }
            node = node->get(i);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(auto &i:word){
            if(!(node->check(i))){
                return false;
            }
            node = node->get(i);
        }
        return node->isLast();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto &i:prefix){
            if(!(node->check(i))) return false;
            node = node->get(i);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */