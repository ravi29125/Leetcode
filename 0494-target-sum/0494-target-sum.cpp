class Solution {
    int ans;
    void help(vector<int>& nums,int target,long long sum,int i){
        if(i==nums.size()){
            if(sum==target)ans++;
            return ;
        }
        help(nums,target,sum+nums[i],i+1);
        help(nums,target,sum-nums[i],i+1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        ans=0;
        help(nums,target,0,0);
        return ans;
    }
};