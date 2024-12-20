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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*> q;
        bool f=false;
        q.push_back(root);
        while(q.size()!=0){
            int n=q.size();
            vector<TreeNode*> t;
            if(f){
                vector<int> arr;
                for(auto k:q){
                    if(!k)continue;
                    arr.push_back(k->val);
                }
                for(auto &k:q){
                    if(!k)continue;
                    n--;
                    k->val=arr[n];
                }
            }
            for(auto k:q){
                if(!k)continue;
                t.push_back(k->left);
                t.push_back(k->right);
            }
            q=t;
            f=!f;
            //cout<<f<<endl;
        }
        return root;
    }
};