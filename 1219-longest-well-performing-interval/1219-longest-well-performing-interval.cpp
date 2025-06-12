class Solution {
public:
    int longestWPI(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int c1=0,c2=0;
            for(int j=i;j<n;j++){
                if(nums[j]<=8)c1++;
                else c2++;
                if(c2>c1){
                    ans=max(ans,j-i+1);
                }
            }
        }return ans;
    }
};