class Solution {
    vector<vector<int>> ans;
    vector<int> nums;
    void help(int i,int n,int k,int sum,vector<int> &arr){
        if(sum>k)return ;
        if(sum==k){
            //sort(arr.begin(),arr.end());
            ans.push_back(arr);
            return ;
        }
        if(i==n){
            return ;
        }
        for(int j=i;j<n;j++){
            if(j>i && nums[j]==nums[j-1]) continue;
            arr.push_back(nums[j]);
            help(j+1,n,k,sum+nums[j],arr);
            arr.pop_back();
        }
        //if(i>0 && nums[i
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans=vector<vector<int>>();vector<int> temp;
        nums=candidates;
        sort(nums.begin(),nums.end());
        help(0,candidates.size(),target,0,temp);
        return ans;
    }
};