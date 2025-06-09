class Solution {
public:
    vector<string> printVertically(string p) {
        string f="";
        vector<string> s;
        for(auto k:p){
            if(k==' '){
                s.push_back(f);
                f="";
            }else f+=k;
        }
        if(f.size()>0)s.push_back(f);
        int n=s.size();
        int mx=0;
        for(auto k:s)mx=max(mx,(int)k.size());
        // for(auto k:s)cout<<k<<endl;
        // cout<<mx<<" ";
        string r(n,'*');
        vector<string> arr(mx,r);
        for(int i=0;i<n;i++){
            for(int j=0;j<mx;j++){
                // cout<<s[i][j]<<" ";
                if(j<s[i].size())
                arr[j][i]=s[i][j];
                else arr[j][i]=' ';
            }
            // cout<<endl;
        }
        for(auto& str:arr){
            while (!str.empty() && isspace(str.back())) {
                str.pop_back();
            }
        }
        return arr;
    }
};