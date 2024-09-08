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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt=0;
        ListNode *curr=head;
        while(curr){
            cnt++;
            curr=curr->next;
        }
        int s=cnt/k;
        int rem=cnt%k;
        curr=head;
        vector<ListNode*> ans(k);
        for(int i=0;i<k && curr;i++){
            ListNode* newhead=curr;
            int j=1;
            if(rem>0){
                rem--;
                j--;
            }
            while(j<s && curr){
                curr=curr->next;
                j++;
            }
            ans[i]=newhead;
            newhead=curr->next;
            curr->next=nullptr;
            curr=newhead;
        }return ans;
    }
};