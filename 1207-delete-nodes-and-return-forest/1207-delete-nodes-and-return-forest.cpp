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
    vector<TreeNode*> ans;
    unordered_set<int> s;
    void del(TreeNode *root){
        //return ;
        if(!root)return ;
        if(root->right){
            if(s.count(root->right->val)){
                root->right=nullptr;
            }else{
                del(root->right);
            }
        }
        if(root->left){
            if(s.count(root->left->val)){
                root->left=nullptr;
            }else{
                del(root->left);
            }
        }
    }
    void recur(TreeNode* root){
        if(!root)return ;
        recur(root->left);
        recur(root->right);
        if(s.count(root->val)){
            if(root->left)
            ans.push_back(root->left);
            if(root->right)
            ans.push_back(root->right);
            root->right=root->left=nullptr;
        }

    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        this->s.clear();
        for(int i:to_delete)s.insert(i);
        ans=vector<TreeNode*>();
        ans.push_back(root);
        recur(root);
        vector<int> in;
        for(int i=0;i<ans.size();i++){
            if(s.count(ans[i][0].val)){
                in.push_back(1);
            }else del(ans[i]),in.push_back(0);
        }
        vector<TreeNode*> re;
        for(int i=0;i<ans.size();i++){
            if(!in[i])re.push_back(ans[i]);
        }
        return re;
    }
};