class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int res=0;
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            int cnt=1;
            string s="";
            for(int j=1;j<m;j++){
                if(mat[i][j]==mat[i][j-1]){
                    cnt++;
                }else{
                    s+=',';
                    s+=to_string(cnt);
                    cnt=1;
                }
            }
            s+=',';
            s+=to_string(cnt);
            //cout<<s<<" ";
            mp[s]++;
            res=max(res,mp[s]);
        }return res;
    }
};