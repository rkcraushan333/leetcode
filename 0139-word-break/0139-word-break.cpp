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
    bool search(string &word)
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
    Trie* t;
    int dp[301];
    bool f(string &s,int i=0)
    {
        if(i==s.size())
        {
            return true;
        }
        int &rkc = dp[i];
        if(rkc!=-1)
        {
            return rkc;
        }
        bool ans = 0;
        string curr = "";
        for(int j=i;j<s.size();j++)
        {
            curr += s[j];
            if(t->search(curr))
            {
                ans |= f(s,j+1);
            }
        }
        return rkc = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    { 
        t = new Trie();
        for(auto i:wordDict)
        {
            t->insert(i);
        }
        memset(dp,-1,sizeof(dp));
        return f(s);
    }
};