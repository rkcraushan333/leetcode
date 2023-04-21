//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

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
class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> &s2){
        // Code here
        Trie *t1 = new Trie();
        for(auto &s:s1) 
        {
            t1->insert(s);
            string ss = s;
            reverse(ss.begin(),ss.end());
            t1->insert(ss);
        }
        int cnt = 0;
        for(auto &s:s2)
        {
            string ss = s;
            reverse(ss.begin(),ss.end());
            if(t1->startsWith(s)||t1->startsWith(ss))
            {
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends