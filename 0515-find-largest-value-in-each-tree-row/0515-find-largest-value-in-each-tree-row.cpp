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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        if(root!=nullptr)q.push(root);
        vector<int> ans;
        while(q.size()>0){
            int n=q.size();
            int val=INT_MIN;
            while(n--){
                auto p=q.front();q.pop();
                val=max(p->val,val);
                if(p->left!=nullptr)q.push(p->left);
                if(p->right!=nullptr)q.push(p->right);
            }
            ans.push_back(val);
        }
        return ans;
    }
};