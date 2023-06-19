class TrieNode{
private:
    TrieNode* child[26];
    bool flag;
public:
    TrieNode()
    {
        for(int i=0;i<26;i++)
        {
            child[i] = NULL;
        }
        flag = false;
    }
    bool check(char c)
    {
        return child[c-'a']!=NULL;
    }
    void create(char c,TrieNode* node)
    {
        child[c-'a']=node;
    }
    TrieNode* getNext(char c)
    {
        return child[c-'a'];
    }
    void setLast()
    {
        flag = true;
    }
    bool isLast()
    {
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
        for(auto i:word)
        {
            if(!node->check(i))
            {
                node->create(i,new TrieNode());
            }
            node = node->getNext(i);
        }
        node->setLast();
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(auto i:word)
        {
            if(node->check(i))
            {
                node = node->getNext(i);
            }
            else
            {
                return false;
            }
        }
        return node->isLast();
    }
    
    bool startsWith(string word) 
    {
        TrieNode* node = root;
        for(auto i:word)
        {
            if(node->check(i))
            {
                node = node->getNext(i);
            }
            else
            {
                return false;
            }
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