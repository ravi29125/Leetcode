class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i:nums){
            if(i%2==0)cnt++;
        }
        int ans=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]%2!=nums[i+1]%2)ans++;
        }
        return max({ans,cnt,n-cnt,});
    }
};