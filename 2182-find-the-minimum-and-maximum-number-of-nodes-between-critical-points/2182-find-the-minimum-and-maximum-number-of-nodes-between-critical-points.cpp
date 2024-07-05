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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *temp=head->next;
        int prev=head->val;
        int i=2;
        int adj,ml=-1,p=-1;
        int mx,mi;
        mx=mi=0;
        adj=INT_MAX;
        while(temp && temp->next){
            if(prev<temp->val && temp->val>temp->next->val){
                if(!(p==-1))adj=min(adj,i-p);
                //if(!(p==-1))cout<<i-p<<" " <<adj<<endl;
                mx=max(mx,i);
                if(!mi)mi=i;
                p=i;
            }else if(prev>temp->val && temp->val<temp->next->val){
                if(!(p==-1))adj=min(adj,i-p);
                //if(!(p==-1))cout<<i-p<<" " <<adj<<endl;
                mx=max(mx,i);
                if(!mi)mi=i;
                p=i;
            }
            i++;
            prev=temp->val;
            temp=temp->next;
        }
        if(mi!=0 && mx!=0 && mi<mx)ml=mx-mi;
        //if(mi!=0 && mx!=0)cout<<mx-mi<<" "<<mx<<" "<<mi;
        return {adj==INT_MAX?-1:adj,ml};
    }
};