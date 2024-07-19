class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int> a(n,INT_MAX),b(m,INT_MIN),ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i]=min(mat[i][j],a[i]);
                b[j]=max(mat[i][j],b[j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=mat[i][j];
                if(val==a[i] && val==b[j])ans.push_back(val);
            }
        }
        //for(int i:a)cout<<i<<" ";cout<<endl;
        //for(int i:b)cout<<i<<" ";cout<<endl;
        return ans;
    }
};