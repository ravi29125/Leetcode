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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long,vector<long long>,greater<>> pq;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            long long ans=0;
            while(size--){
                auto val=q.front();q.pop();
                if(val->left)q.push(val->left);
                if(val->right)q.push(val->right);
                ans+=val->val;
            }
            pq.push(ans);
            if(pq.size()>k)pq.pop();
        }
        if(pq.size()==k)return pq.top();
        return -1;
    }
};