/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> t;
            while(n--){
                auto val= q.front();q.pop();
                if(val->left)q.push(val->left);
                if(val->right)q.push(val->right);
                t.push_back(val->val);
            }ans.push_back(t);
        }return ans;
    }
};