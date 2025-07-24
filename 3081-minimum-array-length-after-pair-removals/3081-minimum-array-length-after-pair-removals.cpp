class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int mx=0,n=nums.size();
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
            mx=max(mx,mp[i]);
        }
        if(mx<=(n/2))return n%2;
        return 2*mx-n;
    }
};