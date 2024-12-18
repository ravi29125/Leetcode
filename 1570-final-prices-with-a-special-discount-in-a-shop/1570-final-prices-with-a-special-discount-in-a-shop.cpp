class Solution {
public:
    vector<int> finalPrices(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);
            for(int j=i+1;j<n;j++){
                if(ans[i]>=nums[j]){
                    ans[i]-=nums[j];
                    break;
                }
            }
        }return ans;
    }
};