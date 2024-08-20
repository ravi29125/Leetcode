class Solution {
    set<vector<int>> ans;
    vector<int> nums;
    void help(int k,vector<int>& temp){
        if(k==0){
            //cout<<curr<<" ";
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return ;
        }
        for(int i:nums){
            if (!temp.empty() && i<temp.back())continue;
            if(k-i >= 0){
                //cout<<curr+i<<" "<<i<<endl;
                temp.push_back(i);
                k-=i;
                help(k,temp);
                k+=i;
                temp.pop_back();
            }else return ;
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        ans=set<vector<int>>();
        nums=candidates;
        vector<int> temp;
        help(target,temp);
        vector<vector<int>> v;
        for(auto k:ans)v.push_back(k);
        return v;    
    }
};