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
    vector<vector<int>>ans;
    void help(TreeNode *root,int n,int i,vector<int> &num){
        if(!root) return;
        if(root && !root->left && !root->right){
            num.push_back(root->val);
            if(i+root->val==n){
                ans.push_back(num);
            }
            num.pop_back();
            return ;
        }
        num.push_back(root->val);
        i+=root->val;
        help(root->left,n,i,num);
        help(root->right,n,i,num);
        i-=root->val;
        num.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        this->ans=vector<vector<int>>();
        vector<int> num;
        int val=0;
        help(root,targetSum,val,num);
        return ans;
    }
};