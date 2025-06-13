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
    unordered_map<int,vector<int>> mp;
    unordered_map<int,int> m;
    void help(TreeNode* root,int cnt,int sign){
        if(root==nullptr) return;
        m[root->val]=cnt*sign;
        mp[cnt*sign].push_back(root->val);
        help(root->right,cnt+1,sign);
        help(root->left,cnt+1,sign);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        set<int> a;
        mp[0].push_back(root->val);
        m[root->val]=0;
        help(root->right,1,1);
        help(root->left,1,-1);
        for(auto p:mp[m[target->val]-k]){
            //for(auto p:kk){
                a.insert(p);
            //}
        }
        for(auto p:mp[m[target->val]+k]){
            //for(auto p:kk){
                a.insert(p);
            //}
        }
        //for(auto l:m)cout<<l.first<<" "<<l.second<<endl;
        vector<int> ans(a.begin(),a.end());
        return ans;
    }
};