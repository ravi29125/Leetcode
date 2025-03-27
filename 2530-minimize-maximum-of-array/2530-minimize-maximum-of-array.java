class Solution {
    public boolean help(int val,int[] nums){
        int n=nums.length;
        long sum=0,cur=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            cur+=val;
            if(sum>cur) return false;
        }return true;
    }
    public int minimizeArrayValue(int[] nums) {
        int n=nums.length;
        int mx=nums[0];
        for(int i=1;i<n;i++){
            mx=Math.max(mx,nums[i]);
        }
        int i=1,j=mx;
        int ans=mx;
        while(i<=j){
            int mid=i+(j-i)/2;
            //System.out.println(mid);
            if(help(mid,nums)){
                ans=mid;
                j=mid-1;
            }else i=mid+1;
        }return ans;
    }
}