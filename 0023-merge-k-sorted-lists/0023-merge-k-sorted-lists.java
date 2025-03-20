/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq=new PriorityQueue<>((a,b)->a.val-b.val);
        int n=lists.length;
        //System.out.println(n);
        for(int i=0;i<n;i++){
            if(lists[i]!=null)
            pq.add(lists[i]);
        }
        ListNode temp,head=null,t1=null;
        //System.out.println(pq);
        while(!pq.isEmpty()){
            temp=pq.poll();
            if(head==null){
                head=temp;
                t1=temp;
            }else{
                t1.next=temp;
                t1=temp;
            }
            if(temp.next!=null)pq.add(temp.next);
        }
        return head;
    }
}