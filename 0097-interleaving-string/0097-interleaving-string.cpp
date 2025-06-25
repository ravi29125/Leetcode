class Solution {
    map<tuple<int,int,int>,int> mp;
    bool help(int i,int j,int k,string &s1,string &s2,string &s3){
        if(k==0 && i==0 && j==0) return true;
        if(i==0 && j==0) return false;
        if(mp.count({i,j,k})) return mp[{i,j,k}];
        bool val = false;
        if(i>0 && k>0 && s1[i-1]==s3[k-1] && help(i-1,j,k-1,s1,s2,s3)){
            val = true;
        }else if(j>0 && k>0 && s2[j-1]==s3[k-1] && help(i,j-1,k-1,s1,s2,s3)){
            val = true;
        }
        return mp[{i,j,k}]=val;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        return help(s1.size(),s2.size(),s3.size(),s1,s2,s3);
    }
};