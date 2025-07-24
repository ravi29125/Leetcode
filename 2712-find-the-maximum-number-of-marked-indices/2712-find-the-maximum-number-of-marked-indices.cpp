class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),m=n/2;
        int cnt=0;
        int i=0,j=m;
        while(i<m && j<n){
            if(nums[i]*2<=nums[j]){
                cnt+=2;
                i++;
                j++;
            }else j++;
        }return cnt;
    }
};