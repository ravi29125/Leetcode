class Solution {
    vector<vector<int>> ans;
    void help(vector<int>& arr,int i,int n,int k,int sum){
        if(sum==n){
            if(k==0)
            ans.push_back(arr);
            return ;
        }
        if(k==0 || i>9 || sum>n)return ;
        arr.push_back(i);
        help(arr,i+1,n,k-1,sum+i);
        arr.pop_back();
        help(arr,i+1,n,k,sum);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ar;
        help(ar,1,n,k,0);
        return ans;
    }
};