class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer> mp=new HashMap<>();
        int n=nums.length;
        int sum=0;
        int ans=0;
        mp.put(0,1);
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int key=sum-k;
            int val=mp.getOrDefault(key,0);
            if(val!=0){
                ans+=val;
            }
            //if(nums[i]==k)ans++;
            mp.put(sum,mp.getOrDefault(sum,0)+1);
        }return ans;
    }
}