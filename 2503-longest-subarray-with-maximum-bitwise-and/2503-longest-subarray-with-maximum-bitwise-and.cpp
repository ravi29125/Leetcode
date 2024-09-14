class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int val=*max_element(nums.begin(),nums.end());
        int cnt=0;
        bool b=false;
        for(int i:nums){
            if(i==val){
                cnt++;
            }else{
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};