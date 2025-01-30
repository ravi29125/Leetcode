class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mx=INT_MAX;
        int j=0,n=nums.size();
        long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>=target){
                mx=min(mx,i-j+1);
                //cout<<i<<" "<<j<<endl;
            }
            while(sum>=target){
                mx=min(mx,i-j+1);
                sum-=nums[j++];
            }
        }return mx==INT_MAX?0:mx;
    }
};