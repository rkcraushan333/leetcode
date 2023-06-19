class TrieNode{
    private:
    TrieNode* child[2];
    public:
    TrieNode(){
        for(int i=0;i<2;i++)
        {
            child[i] = NULL;
        }
    }
    bool check(char c)
    {
        return child[c-'0']!=NULL;
    }
    void create(char c,TrieNode* node)
    {
        child[c-'0'] = node;
    }
    TrieNode* getNext(char c)
    {
        return child[c-'0'];
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
            node = node->getNext(i);
        }
    }
    string maxXor(string &s)
    {
        string ans = "";
        TrieNode* node = root;
        for(auto i:s)
        {
            if(i=='0')
            {
                if(node->check('1'))
                {
                    ans += '1';
                    node = node->getNext('1');
                }
                else
                {
                    ans += '0';
                    node = node->getNext('0');
                }
            }
            else
            {
                if(node->check('0'))
                {
                    ans += '1';
                    node = node->getNext('0');
                }
                else
                {
                    ans += '0';
                    node = node->getNext('1');
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    string decToBin(int n)
    {
        string s;
        while(n)
        {
            s += '0'+(n%2);
            n /= 2;
        }
        while(s.size()<31)
        {
            s += '0';
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int binToDec(string &s)
    {
        int ans = 0;
        reverse(s.begin(),s.end());
        for(int i=0;i<32;i++)
        {
            if(s[i]=='1')
            {
                ans += pow(2,i);
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) 
    {
        Trie* t = new Trie();
        int ans = 0;
        for(auto i:nums)
        {
            string s = decToBin(i);
            t->insert(s);
        }
        for(auto i:nums)
        {
            string s = decToBin(i);
            string temp = t->maxXor(s);
            // cout<<temp<<endl;
            ans = max(ans,binToDec(temp));
        }
        return ans;
    }
};