class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        long sum=0;
        for(int i:nums)sum+=i;
        int n=nums.size();
        int val=n-k;
        int j=0;
        int i=0;
        long curr=0;
        while(val--)curr+=nums[i++];
        int ans=(int)curr;
        while(i<n){
            curr+=nums[i++];
            curr-=nums[j++];
            ans=min(ans,(int)curr);
        }return sum-ans;
    }
};