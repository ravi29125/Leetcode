class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int g) {
        unordered_map<int,int> mp;
        int cnt=0;
        mp[0]++;
        int cur=0;
        for(int i:nums){
            cur+=i;
            cnt+=mp[cur-g];
            mp[cur]++;
        }return cnt;
    }
};