class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int i=0,j=-1,m=matrix[0].size(),n=matrix.size();
        while(i<n && j<m){
            for(int h=i;h<m;h++){
                ans.push_back(matrix[i][h]);
            }
            m--;
            for(int h=i+1;h<n;h++){
                ans.push_back(matrix[h][m]);
            }
            n--;
            for(int h=m-1;h>j;h--){
                ans.push_back(matrix[n][h]);
                //cout<<ans[ans.size()-1]<<" ";
            }
            j++;
            for(int h=n-1;h>i;h--){
                ans.push_back(matrix[h][j]);
                //cout<<ans[ans.size()-1]<<" ";
            }
            i++;
            //cout<<i<<" "<<j<<" "<<m<<" "<<n<<endl;
        }
        ans.resize(matrix[0].size()*matrix.size());
        return ans;
    }
};