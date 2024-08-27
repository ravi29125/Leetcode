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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool f=true;
        while(!q.empty()){
            int n=q.size();
            vector<int> t;
            while(n--){
                auto val=q.front();q.pop();
                if(!val)continue;
                t.push_back(val->val);
                if(val->left)
                q.push(val->left);
                if(val->right)
                q.push(val->right);
            }
            if(!f){
                reverse(t.begin(),t.end());
            }
            //f=!f;
            ans.push_back(t);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};