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
    int cnt;
    vector<int> help(TreeNode *root,int d){
        if(!root->left && !root->right){
            return {1};
        }else{
            vector<int> a,b;
            if(root->left){
                a=help(root->left,d);
            }
            if(root->right){
                b=help(root->right,d);
            }
            for(int i:a){
                for(int j:b){
                    if(i+j <= d)cnt++;
                }
            }
            vector<int> ans;
            for(int i:a){
                if(i+1<d)
                ans.push_back(i+1);
            }
            for(int i:b){
                if(i+1<d)
                ans.push_back(i+1);
            }return ans;
        }return {};
    }
public:
    int countPairs(TreeNode* root, int distance) {
        this->cnt=0;
        vector<int> p=help(root,distance);
        return cnt;
    }
};