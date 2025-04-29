class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int cnt=0,maxii=*max_element(nums.begin(),nums.end());
        int i=0,j,n=nums.size();
        for(j=0;j<n;j++){
            if(nums[j]==maxii){
                cnt++;
                while(cnt==k){
                    ans+=(n-j);
                    if(nums[i]==maxii){
                        cnt--;
                    }i++;
                }
            }
        }return ans;
    }
};