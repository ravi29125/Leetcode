class Solution {
public:
    bool makeStringsEqual(string s1, string s2) {
        bool f=false,p=false;
        for(auto k:s1)if(k=='1')f=true;
        for(auto k:s2)if(k=='1')p=true;
        return f==p;
    }
};