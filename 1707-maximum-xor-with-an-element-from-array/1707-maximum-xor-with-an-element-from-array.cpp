class TrieNode{
    private:
    TrieNode* child[2];
    public:
    TrieNode()
    {
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
        TrieNode* node = root;
        string ans = "";
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
bool cmp(vector<int>&a,vector<int>&b)
{
      return a[1]<b[1];
}
class Solution {
public:
    string d2b(int n)
    {
        string s = "";
        for(int i=0;i<31;i++)
        {
            s += '0'+(n%2);
            n /= 2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int b2d(string &s)
    {
        int ans = 0;
        reverse(s.begin(),s.end());
        for(int i=0;i<31;i++)
        {
            if(s[i]=='1')
            {
                ans += pow(2,i);
            }
        }
        return ans;
    }
    // Using Offline queries concept
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries)     {
        for(int j=0;j<queries.size();j++)
        {
            queries[j].push_back(j);
        }
        sort(nums.begin(),nums.end());
        sort(queries.begin(),queries.end(),cmp);
        Trie* t = new Trie();
        int i = 0;
        vector<int>v(queries.size());
        for(auto vv:queries)
        {
            int a = vv[0], b = vv[1], c = vv[2];
            while(i<nums.size()&&nums[i]<=b)
            {
                string st = d2b(nums[i]);
                t->insert(st);
                i++;
            }
            if(i==0) 
            {
                v[c] = -1;
            }
            else
            {
                string temp1 = d2b(a);
                string temp2 = t->maxXor(temp1);
                v[c] = b2d(temp2);
            }
        }
        return v;
    }
};