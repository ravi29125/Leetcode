class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums) {
        int cnt=0;
        nums.push_back(nums[0]);
        nums.push_back(nums[1]);
        int n=nums.size();
        for(int i=1;i<n-1;i++){
            if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1])cnt++;
        }return cnt;
    }
};