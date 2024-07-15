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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        //mp[0]=new TreeNode(10);
        vector<int> a;
        unordered_set<int> s;
        for(auto k:descriptions){
            int from=k[0];
            int to=k[1];
            int dir=k[2];
            s.insert(to);
            a.push_back(from);
            if(mp.find(from)==mp.end())mp[from]=new TreeNode(from);
            if(mp.find(to)==mp.end())mp[to]=new TreeNode(to);
            if(dir==0){
                mp[from]->right=mp[to];
            }else{
                mp[from]->left=mp[to];
            }
        }
        for(int i:a)if(s.find(i)==s.end())return mp[i];
        return nullptr;
    }
};
