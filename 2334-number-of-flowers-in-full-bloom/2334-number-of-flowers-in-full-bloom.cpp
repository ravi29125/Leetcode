class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        int n=p.size();
        vector<int> s,e;
        for(auto k:f){
            s.push_back(k[0]);
            e.push_back(k[1]);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        for(int i=0;i<n;i++){
            int st=upper_bound(s.begin(),s.end(),p[i])-s.begin();
            int end=lower_bound(e.begin(),e.end(),p[i])-e.begin();
            p[i]=st-end;
        }
        return p;
    }
};