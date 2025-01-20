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
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int,Node*> name;
    unordered_map<int,vector<int>> mp;
    void help(Node *node){
        if(node && name.find(node->val)==name.end()){
            name[node->val]=new Node(node->val);
            for(auto k:node->neighbors){
                help(k);
                mp[node->val].push_back(k->val);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        help(node);
        for(auto k:mp){
            for(auto j:k.second){
                name[k.first]->neighbors.push_back(name[j]);
            }
        }
        return name[node->val];
    }
};