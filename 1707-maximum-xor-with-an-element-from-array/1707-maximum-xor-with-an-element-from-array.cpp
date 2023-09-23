class TrieNode
{
    vector<TrieNode*>child;
public:
    TrieNode()
    {
        child.resize(2);
        child[0] = NULL; child[1] = NULL;
    }
    bool check(char c)
    {
        return child[c-'0']!=NULL;
    }
    TrieNode* getNext(char c)
    {
        return child[c-'0'];
    }
    void create(char c,TrieNode* node1)
    {
        child[c-'0'] = node1;
    }
};
class Trie
{
    TrieNode* root;
public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string s)
    {
        TrieNode* node = root;
        for(auto i:s)
        {
            if(!node->check(i))
                node->create(i,new TrieNode());
            node = node->getNext(i);
        }
    }
    string findMax(string s)
    {
        string ans= "";
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
                    node =  node->getNext('0');
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
    string d2b(int n)
    {
        string s = "";
        while(n)
        {
            if(n%2==0) s += '0';
            else s += '1';
            n /= 2;
        }
        while(s.size()<32)
        {
            s += '0';
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int b2d(string &s)
    {
        int ans = 0;
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                ans |= (1<<i);
            }
        }
        return ans;
    }
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) 
    {
        for(int i=0;i<queries.size();i++)
        {
            queries[i].push_back(i);
        }
        Trie* t = new Trie();
        sort(nums.begin(),nums.end());
        sort(queries.begin(),queries.end(),cmp);
        int i=0,j=0;
        vector<int>ans(queries.size());
        while(j<queries.size())
        {
            while(i<nums.size()&&queries[j][1]>=nums[i])
            {
                string s1 = d2b(nums[i]);
                t->insert(s1);
                i++;
            }
            if(i==0) ans[queries[j][2]]=-1;
            else{
            string s2 = d2b(queries[j][0]);
            string t1 = t->findMax(s2);
            ans[queries[j][2]]=b2d(t1);
            }
            j++;
        }
        return ans;
    }
};