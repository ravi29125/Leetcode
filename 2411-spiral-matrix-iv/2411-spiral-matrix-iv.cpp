/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m,vector<int>(n,-1));
        int i=0,j=-1;
        int l=m;
        m=n;
        n=l;
        while(i<n && j<m){
            for(int h=i;h<m&&head;h++){
                matrix[i][h]=head->val;
                head=head->next;
            }
            m--;
            for(int h=i+1;h<n&&head;h++){
                matrix[h][m]=head->val;
                head=head->next;
            }
            n--;
            for(int h=m-1;h>j&&head;h--){
                matrix[n][h]=head->val;
                head=head->next;
            }
            j++;
            for(int h=n-1;h>i&&head;h--){
                matrix[h][j]=head->val;
                head=head->next;
            }
            i++;
        }return matrix;
    }
};