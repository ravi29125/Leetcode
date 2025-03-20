class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n=nums.length;
        int size=n-(k-1);
        int[] ans=new int[size];
        int index=0;
        TreeMap<Integer,Integer> map=new TreeMap<>();
        for(int i=0;i<n;i++){
            if(i<k){
                map.put(nums[i],map.getOrDefault(nums[i],0)+1);
            }else{
                map.put(nums[i],map.getOrDefault(nums[i],0)+1);
                int val=map.get(nums[i-k]);
                if(val==1)map.remove(nums[i-k]);
                else map.put(nums[i-k],val-1);
            }
            if(i>=k-1)
            ans[index++]=map.lastKey();
        }return ans;
    }
}