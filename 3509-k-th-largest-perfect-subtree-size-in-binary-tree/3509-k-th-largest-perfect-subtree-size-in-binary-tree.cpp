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
    vector<int> arr;
    pair<int, int> help(TreeNode* root) {
        if (root) {
            pair<int, int> q, w;
            q = help(root->right), w = help(root->left);
            if (q.first == -1 || w.first == -1)
                return {-1, 0};
            else if (q.first == w.first && q.second == w.second &&
                     w.first == w.second) {
                arr.push_back(q.first * 2 + 1);
                return {q.first * 2 + 1, q.first * 2 + 1};
            } else
                return {-1, 0};
        }
        return {0, 0};
    }

public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        arr = vector<int>();
        pair<int, int> p = help(root);
        // if(p.first!=-1)arr.push_back(p.first);
        if (k > arr.size())
            return -1;
        sort(arr.begin(), arr.end(), greater<int>());
        for (int i : arr)
            cout << i << " ";
        return arr[k - 1];
    }
};