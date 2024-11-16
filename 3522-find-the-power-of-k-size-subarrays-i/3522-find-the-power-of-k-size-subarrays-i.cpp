class Solution {
    int help(int m,int n,vector<int>&nums,int k){
        int i=m-k+1;
        while(i<m && nums[i]==nums[i-1]+1)i++;
        return i==m?nums[m-1]:-1;
    }
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> arr;
        for(int i=k;i<=n;i++){
            arr.push_back(help(i,n,nums,k));
        }return arr;
    }
};