class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& nums) {
        double sum=0;
        int n=nums.size();
        long curr=0;
        for(int i=0;i<n;i++){
            if(curr<nums[i][0]){
                curr=nums[i][0];
            }
            curr+=nums[i][1];
            sum+=curr-nums[i][0];
        }return sum/n;
    }
};