class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int j=0;
        for(int i:nums){
            j++;
            if(mp[target-i]!=0)return {j-1,mp[target-i]-1};
            mp[i]=j;
        }return {};
    }
};