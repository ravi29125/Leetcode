class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        int j=n-1;
        vector<int> ans(n,0);
        vector<int> curr;
        for(int i=n-1;i>-1;i--){
            auto it=lower_bound(curr.begin(),curr.end(),nums[i]);
            int val=it-curr.begin();
            if(it!=curr.end())
            curr.insert(it,nums[i]);
            else curr.push_back(nums[i]);
            ans[j--]=val;
        }return ans;
    }
};