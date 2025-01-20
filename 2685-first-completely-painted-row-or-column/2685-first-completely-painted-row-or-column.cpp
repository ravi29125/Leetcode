class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int> rows(n),cols(m);
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        int j=-1;
        for(int &i:arr){
            j++;
            rows[mp[i].first]++;
            cols[mp[i].second]++;
            //cout<<mp[i].first<<" "<<mp[i].second<<endl;
            if(rows[mp[i].first]==m || cols[mp[i].second]==n) return j;
        }return j;
    }
};