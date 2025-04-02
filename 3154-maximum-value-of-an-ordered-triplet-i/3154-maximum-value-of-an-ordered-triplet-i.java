class Solution {
    public long maximumTripletValue(int[] nums) {
        long n=nums.length,mx=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    long val=(long)(nums[i]-nums[j])*nums[k];
                    mx=Math.max(mx,val);
                }
            }
        }
        return mx;
    }
}