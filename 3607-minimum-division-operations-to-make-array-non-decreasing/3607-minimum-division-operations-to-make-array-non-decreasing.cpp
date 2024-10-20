class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=n-2;i>-1;i--){
            if(nums[i]>nums[i+1]){
                if(nums[i]%2==0)nums[i]=2;
                else{
                    int j;
                    bool b=false;
                    for(j=3;j*j<=nums[i];j++){
                        if(nums[i]%j==0){
                            nums[i]=j;
                            b=true;
                            break;
                        }
                    }
                    if(!b || nums[i]>nums[i+1])return -1;
                }ans++;
            }
        }return ans;
    }
};