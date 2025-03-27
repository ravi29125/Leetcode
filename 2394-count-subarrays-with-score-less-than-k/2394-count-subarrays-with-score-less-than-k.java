class Solution {
    public long countSubarrays(int[] nums, long k) {
        long ans=0,cur=0;
        int j=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            cur+=nums[i];
            while(cur*(i-j+1)>=k){
                cur-=nums[j++];
            }
            //System.out.println(i+" "+j);
            long nn=i-j+1;
            ans+=nn;
        }
        return ans;
    }
}