class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=0,curr=0;
        for(int i:nums)sum+=i;
        int ans=-1;
        if(sum<0){
            ans=0;
        }
        for(int i:nums){
            curr+=i;
            sum-=i;
            if(curr>=sum)ans++;
        }return ans==-1 ? 0:ans;
    }
};