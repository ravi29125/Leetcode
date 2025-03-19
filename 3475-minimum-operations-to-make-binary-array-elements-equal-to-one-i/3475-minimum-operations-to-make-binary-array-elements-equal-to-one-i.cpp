class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<=n-3;i++){
            if(nums[i]==0){
                cnt++;
                for(int j=0;j<3;j++){
                    nums[i+j]=1-nums[i+j];
                }
            }
        }return (nums[n-1]==0 || nums[n-2]==0)?-1:cnt;
    }
};