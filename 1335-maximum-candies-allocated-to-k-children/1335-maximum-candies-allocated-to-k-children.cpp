class Solution {
    bool help(int k,vector<int>& nums,long long seat){
        long long cnt=0;
        for(int i:nums){
            cnt+=i/k;
        }
        return seat<=cnt;
    }
public:
    int maximumCandies(vector<int>& nums, long long k) {
        int i=1;
        int j=(*max_element(nums.begin(),nums.end()));
        int ans=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(help(mid,nums,k)){
                ans=mid;
                i=mid+1;
            }else{
                j=mid-1;
            }
        }return ans;
    }
};