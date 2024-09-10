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
    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode ls=head;
        while(ls!=null && ls.next!=null){
            int gc = gcd(ls.val,ls.next.val);
            ListNode temp=new ListNode(gc,ls.next);
            ls.next=temp;
            ls=temp.next;
        }return head;
    }
}