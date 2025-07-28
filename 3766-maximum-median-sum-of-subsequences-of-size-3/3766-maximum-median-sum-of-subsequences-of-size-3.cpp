class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while((j-i+1)>0){
            j--;
            ans+=nums[j--];
            i++;
        }
        return ans;
    }
};