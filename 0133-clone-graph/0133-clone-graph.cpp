/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbours = _neighbours;
    }
};
*/
class Solution {
public:
        unordered_map<Node*,Node*>m;
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        if(m.find(node)==m.end()){
           m[node]=new Node(node->val,{});
           for(auto i : node->neighbors){
               m[node]->neighbors.push_back(cloneGraph(i));
           }
        }
        return m[node];
     }
};