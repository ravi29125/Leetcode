class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> pre(n+1,0);
        int val=0;
        for(int i=0;i<n;i++){
            pre[i]=val;
            val^=arr[i];
        }
        pre[n]=val;
        vector<int> ans(queries.size(),0);
        int j =0;
        for(auto k:queries){
            ans[j++]=pre[k[1]+1]^pre[k[0]];
        }return ans;
    }
};