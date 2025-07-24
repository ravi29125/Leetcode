class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& b) {
        int n=b.size(),m=b[0].size();
        // for(auto k:b){for(auto p:k)cout<<p<<" ";cout<<endl;}
        vector<vector<char>> arr(m,vector<char>(n,'.'));
        for(int i=0;i<n;i++){
            int r=n-1-i;
            int k=m-1;
            for(int j=m-1;j>-1;j--){
                if(b[i][j]=='#'){
                    arr[k--][r]='#';
                }else if(b[i][j]=='*'){
                    arr[j][r]='*';
                    k=j-1;
                }
            }
        }
        // reverse(arr.begin(),arr.end());
        // for(auto k:arr){for(auto p:k)cout<<p<<" ";cout<<endl;}
        return arr;
    }
};