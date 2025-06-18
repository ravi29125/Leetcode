class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        //bool b=false;
        vector<vector<int>> ans(n/3),a;
        multiset<int> m;
        for(auto p:nums) m.insert(p);
        int j=0;
        for(auto p:m){
            ans[j].push_back(p);
            if(ans[j].size()==3){
                if((ans[j][2]-ans[j][0])>k){
                    ans.clear();
                    return ans;
                }
                j++;
            }
        }return ans;
    }
};