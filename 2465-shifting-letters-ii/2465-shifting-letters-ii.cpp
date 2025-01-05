class Solution {
    char help(char s,int val){
        int v=val+int(s);
        int ref1=int('a');
        int ref2=int('z');
        if(v<=ref2 && v>=ref1)return (char)v;
        else if(v<ref1){
            int c=ref1-v;
            return 'z'-c+1;
        }
        return 'a'+(v-ref2-1);
    }
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> h1(n+1,0),h2(n+1,0);
        for(auto &k:shifts){
            if(k[2]==1){
                h1[k[0]]+=1;
                h1[k[1]+1]-=1;
            }else{
                h2[k[0]]+=1;
                h2[k[1]+1]-=1;
            }
        }
        for(int i=1;i<=n;i++){
            h1[i]+=h1[i-1];
            h2[i]+=h2[i-1];
        }
        string ans="";
        for(int i=0;i<n;i++){
            int val=(h1[i]-h2[i])%26;
            //cout<<val<<" ";
            ans+=help(s[i],val);
        }
        return ans;
    }
};