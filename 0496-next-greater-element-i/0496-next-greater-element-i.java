class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> st=new Stack<>();
        int n=nums2.length;
        HashMap<Integer,Integer> map=new HashMap<>();
        for(int i=n-1;i>-1;i--){
            while(!st.empty() && st.peek()<nums2[i])st.pop();
            if(st.empty())map.put(nums2[i],-1);
            else map.put(nums2[i],st.peek());
            st.push(nums2[i]);
        }
        int m=nums1.length;
        int[] ans=new int[m];
        for(int i=0;i<m;i++){
            ans[i]=map.get(nums1[i]);
        }return ans;
    }
}