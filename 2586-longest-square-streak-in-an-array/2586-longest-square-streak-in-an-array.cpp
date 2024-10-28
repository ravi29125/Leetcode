class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end());
        int ans=-1;
        for(int i:nums){
            int val=sqrt(i);
            if(val*val==i && mp.find(val)!=mp.end()){
                mp[i]=mp[val]+1;
                ans=max(ans,mp[i]);
            }else{
                mp[i]=1;
            }
        }return ans;
    }
};