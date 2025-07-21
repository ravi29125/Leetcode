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
    void help(TreeNode* root,vector<int>& arr){
        if(!root) return ;
        help(root->left,arr);
        arr.push_back(root->val);
        help(root->right,arr);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> arr;
        help(root,arr);
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i-1]>=arr[i]) return false;
        }return true;
    }
};