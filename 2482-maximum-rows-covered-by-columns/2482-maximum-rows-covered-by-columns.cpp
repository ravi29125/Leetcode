class Solution {
    vector<vector<int>> arr;
    void help(int st,int n,int k,vector<int>& a){
        if(a.size()==k){
            arr.push_back(a);
            return ;
        }
        if(st==n){
            return ;
        }
        a.push_back(st);
        help(st+1,n,k,a);
        a.pop_back();
        help(st+1,n,k,a);
    }
public:
    int maximumRows(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();
        vector<int> a;
        help(0,m,k,a);
        int ans=0;
        for(auto pp:arr){
            unordered_set<int> s;
            for(int i:pp){
                s.insert(i);
            }
            int a=0;
            for(int i=0;i<n;i++){
                int f=true;
                for(int j=0;j<m;j++){
                    if(mat[i][j]==1){
                        if(s.count(j)){

                        }else{
                            f=false;
                            break;
                        }
                    }
                }
                if(f)a++;
            }
            ans=max(ans,a);
        }
        return ans;
    }
};