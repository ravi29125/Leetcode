class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int ans=0,n=nums.length,j=0;
        long cum=0;
        //System.out.println(Arrays.toString(nums));
        for(int i=0;i<n;i++){
            cum+=nums[i];
            while(cum+k<(long)(i-j+1)*nums[i])cum-=nums[j++];
            ans=Math.max(ans,i-j+1);
        }
        return ans;
    }
}