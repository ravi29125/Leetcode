class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(auto k:op){
            nums[mp[k[0]]]=k[1];
            mp[k[1]]=mp[k[0]];
        }return nums;
    }
};