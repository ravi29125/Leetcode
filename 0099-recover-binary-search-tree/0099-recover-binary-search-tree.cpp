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
    vector<int> arr;
    int i=0;
    void help(TreeNode *root){
        if(root){
            help(root->left);
            arr.push_back(root->val);
            help(root->right);
        }
    }
    void re(TreeNode *root){
        if(root){
            re(root->left);
            root->val=arr[i++];
            re(root->right);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        help(root);
        sort(arr.begin(),arr.end());
        re(root);
    }
};