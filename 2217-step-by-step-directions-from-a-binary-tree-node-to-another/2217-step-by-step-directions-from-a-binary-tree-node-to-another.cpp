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
    string te="";
    void countp(TreeNode* root,int p,int c){
        if(!root)return ;
        if(root->val==p){
            cnt=c;
            return ;
        }else{
            countp(root->left,p,c+1);
            countp(root->right,p,c+1);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
        if(root==nullptr)return nullptr;
        if(root->val==p || root->val==q)return root;
        TreeNode *left,*right;
        left=lowestCommonAncestor(root->left,p,q);
        right=lowestCommonAncestor(root->right,p,q);
        if(left!=nullptr && right!=nullptr)return root;
        return right==nullptr ? left:right;
    }
    void search(TreeNode* root, int p,string &c){
        if(!root)return ;
        if(te.size()!=0)return;
        if(root->val==p){
            te=c;
            return ;
        }else{
            if(te.size()!=0)return;
            c.push_back('L');
            search(root->left,p,c);
            c.pop_back();
            if(te.size()!=0)return;
            c.push_back('R');
            search(root->right,p,c);
            c.pop_back();
        }
    }
public:
    string getDirections(TreeNode* root, int p, int q) {
        TreeNode *head=lowestCommonAncestor(root,p,q);
        //if(head)cout<<head->val;
        string s="";
        this->te="";
        string g="";
        if(head->val==p){
            search(head,q,g);
        }else if(head->val==q){
            this->cnt=0;
            countp(head,p,0);
            //cout<<cnt<<endl;
            while(cnt--)s+='U';
        }else{
            this->cnt=0;
            countp(head,p,0);
            //cout<<cnt<<endl;
            while(cnt--)s+='U';
            search(head,q,g);
        }
        //cout<<te;
        s+=te;
        //if(head)cout<<head->val;
        return s;
    }
};