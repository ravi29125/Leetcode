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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mp;
        for(int i:nums)mp[i]++;
        ListNode* temp=head,*prev;
        while(temp!=nullptr && temp->next!=nullptr){
            if(temp->next->next==nullptr){
                if(mp[temp->next->val]!=0){
                    temp->next=nullptr;
                }
            }
            if(!mp[temp->val]){
                prev=temp;
                temp=temp->next;
            }else{
                if(temp->next==nullptr){
                    prev->next=nullptr;
                    temp=prev;
                    continue;
                }
                temp->val=temp->next->val;
                temp->next=temp->next->next;
            }
        }
        return head;
    }
};