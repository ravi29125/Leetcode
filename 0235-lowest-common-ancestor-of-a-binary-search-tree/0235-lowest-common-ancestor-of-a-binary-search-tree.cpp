/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p1, TreeNode* q1) {
        TreeNode *temp=root;
        TreeNode * p,* q;
        if(p1->val<q1->val){
            p=p1;
            q=q1;
        }else{
            p=q1;
            q=p1;
        }
        while(temp!=nullptr){
            if(!temp->left && !temp->right) return nullptr;
            if(temp==p || temp==q)return temp;
            if(temp->left && temp->right && p->val<temp->val && temp->val<q->val){
                //cout<<"HERE";
                return temp;
            }else if(temp->left && q->val<temp->val){
                //cout<<"HERE";
                temp=temp->left;
            }else{
                //cout<<"HERE";
                temp=temp->right;
            }
        }return nullptr;
    }
};