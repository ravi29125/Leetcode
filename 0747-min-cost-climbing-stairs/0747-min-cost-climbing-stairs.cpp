class Solution {
public:
    int minCostClimbingStairs(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n+1);
        arr[0]=nums[0];
        arr[1]=nums[1];
        for(int i=2;i<=n;i++){
            arr[i]=min(arr[i-1],arr[i-2]);
            if(i<n)arr[i]+=nums[i];
        }return arr[n];
    }
};