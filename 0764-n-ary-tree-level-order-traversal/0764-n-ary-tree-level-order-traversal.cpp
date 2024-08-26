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
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node *> q;
        vector<vector<int>> ans;
        if(!root)return ans;
        q.push(root);
        while(!q.empty()){
            vector<int> t;
            int n=q.size();
            while(n--){
                auto val=q.front();
                q.pop();
                t.push_back(val->val);
                for(auto k:val->children)if(k)q.push(k);
            }
            ans.push_back(t);
        }return ans;
    }
};