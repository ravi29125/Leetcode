class Solution {
public:
    int subsetXORSum(vector<int>& nums,int i=0,int s=0) {
        if(i==nums.size())return s;
        return subsetXORSum(nums,i+1,s)+subsetXORSum(nums,i+1,s^nums[i]);
    }
};