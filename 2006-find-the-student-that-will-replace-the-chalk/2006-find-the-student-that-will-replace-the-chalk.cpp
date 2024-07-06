class Solution {
public:
    int chalkReplacer(vector<int>& nums, int k) {
        int n=nums.size();
        long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        k%=sum;
        sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>k)return i;
        }return -1;
    }
};