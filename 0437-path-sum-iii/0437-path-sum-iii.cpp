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
    int ans;
    unordered_map<long long,int> mp;
    //unordered_map<int,int> p;
    void help(TreeNode* root,long long s,int t){
        if(root->left==nullptr && root->right==nullptr){
            s+=root->val;
            //p[root->val]++;
            //for(int i:s)cout<<i<<" ";cout<<endl;
            //ans+=subarraySum(s,t);
            if(mp.find(s-t)!=mp.end())ans+=mp[s-t];
            mp[s]++;
            //cout<<subarraySum(s,t)<<" "<<endl;
            mp[s]--;
            s-=root->val;
            return ;
        }
        //p[root->val]++;
        s+=root->val;
        if(mp.find(s-t)!=mp.end())ans+=mp[s-t];
        mp[s]++;
        if(root->right)help(root->right,s,t);
        if(root->left)help(root->left,s,t);
        mp[s]--;
        s-=root->val;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        ans=0;
        //vector<int> s;
        mp.clear();
        mp[0]++;
        help(root,0,targetSum);
        //for(auto k:mp)cout<<k.first<<" "<<k.second<<endl;
        return ans;
    }
};