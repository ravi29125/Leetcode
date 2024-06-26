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
    void inorder(TreeNode * root,vector<TreeNode *> &res){
        if(root){
            inorder(root->left,res);
            res.push_back(root);
            inorder(root->right,res);
        }
    }
    TreeNode* help(vector<TreeNode *> &res,int i,int j){
        if(i>j)return nullptr;
        int mid=(i+j)/2;
        res[mid]->left=help(res,i,mid-1);
        res[mid]->right=help(res,mid+1,j);
        return res[mid];
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode *> res;
        inorder(root,res);
        return help(res,0,res.size()-1);
    }
};