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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool b=true;
        while(!q.empty()){
            int size=q.size();
            int mi=INT_MIN,mx=INT_MAX;
            while(size--){
                auto val=q.front();q.pop();
                if(val->left)q.push(val->left);
                if(val->right)q.push(val->right);
                if(b){
                    if(val->val%2==0 || mi>=val->val)return false;
                    mi=val->val;
                }else{
                    if(val->val%2==1 || mx<=val->val)return false;
                    mx=val->val;
                }
            }
            b=!b;
        }return -1;
    }
};