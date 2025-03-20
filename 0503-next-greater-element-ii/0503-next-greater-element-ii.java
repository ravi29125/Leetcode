class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n=nums.length;
        Stack<Integer> st=new Stack<>();
        int[] ans=new int[n];
        for(int i=0;i<n;i++){
            ans[i]=-1;
        }
        for(int i=0;i<2*n;i++){
            int val=nums[i%n];
            while(!st.isEmpty() && nums[st.peek()]<val){
                ans[st.pop()]=val;
            }
            if(i<n) st.push(i);
        }
        return ans;
    }
}