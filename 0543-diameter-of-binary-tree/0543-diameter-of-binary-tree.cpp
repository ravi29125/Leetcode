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
    int ans;
    int help(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int l=help(root->left),r=help(root->right);
        ans=max(ans,l+r);
        return 1+max(l,r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        ans=0;
        help(root);
        //cout<<l<<" "<<r;
        return ans;
    }
};