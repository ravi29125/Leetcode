class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt=0,ans=0,curr=0;
        int j=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0)cnt++;
            curr+=nums[i];
            while(cnt>k){
                if(nums[j]==0)cnt--;
                curr-=nums[j++];
            }
            ans=max(ans,i-j+1);
        }return ans;
    }
};