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
    void flatten(TreeNode* root) {
        stack<TreeNode* > st;
        if(root)
        st.push(root);
        TreeNode* temp=nullptr;
        while(!st.empty()){
            auto t=st.top();st.pop();
            if(t->right)st.push(t->right);
            if(t->left)st.push(t->left);
            t->left=t->right=nullptr;
            if(temp){
                temp->right=t;
            }
            temp=t;
        }
    }
};