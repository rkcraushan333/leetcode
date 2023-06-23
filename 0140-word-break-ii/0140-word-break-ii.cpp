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
        child[c-'a'] = node;
    }
    TrieNode* get(char c)
    {
        return child[c-'a'];
    }
    void setLast()
    {
        flag = true;
    }
    bool getLast()
    {
        return flag;
    }
};
class Trie{
private:
    TrieNode* root;
public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string &word)
    {
        TrieNode* node = root;
        for(auto i:word)
        {
            if(!node->check(i))
            {
                node->create(i,new TrieNode());
            }
            node = node->get(i);
        }
        node->setLast();
    }
    bool check(string &word)
    {
        TrieNode* node = root;
        for(auto i:word)
        {
            if(!node->check(i)) return false;
            node = node->get(i);
        }
        return node->getLast();
    }
};
class Solution {
public:
    vector<string>res;
    Trie* t;
    void f(string &s,int i=0,string last="")
    {
        if(i==s.size())
        {
            res.push_back(last);
            return;
        }
        string curr = "";
        for(int j=i;j<s.size();j++)
        {
            curr += s[j];
            if(t->check(curr))
            {
                if(j==s.size()-1)
                {
                    f(s,j+1,last+curr);
                }
                else
                {
                    f(s,j+1,last+curr+" ");
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        t = new Trie();
        for(auto i:wordDict)
        {
            t->insert(i);
        }
        f(s);
        return res;
    }
};