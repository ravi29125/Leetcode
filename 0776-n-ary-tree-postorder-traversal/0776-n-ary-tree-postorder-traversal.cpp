/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<int> ans;
    void help(Node *root){
        if(!root)return ;
        for(auto i:root->children) help(i);
        ans.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        ans=vector<int>();
        help(root);
        return ans;
    }
};