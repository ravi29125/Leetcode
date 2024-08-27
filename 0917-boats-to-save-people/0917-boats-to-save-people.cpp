class Solution {
public:
    int numRescueBoats(vector<int>& nums, int l) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1,ans=0;
        while(i<=j){
            if(i!=j && nums[i]+nums[j]<=l){
                ans++;
                i++;
                j--;
            }else if(nums[j]<=l){
                ans++;
                j--;
            }else{
                ans++;
                i++;
            }
        }return ans;
    }
};