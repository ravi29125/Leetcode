class Solution {
    bool help(set<int>& s1,set<int>& s2){
        if(s1.size()!=s2.size())return false;
        for(int i:s1)if(s2.count(i)==0)return false;
        return true;
    }
public:
    int maxChunksToSorted(vector<int>& arr) {
        set<int> s1,s2;
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            s1.insert(i);
            s2.insert(arr[i]);
            if(help(s1,s2)){
                s1.clear();
                s2.clear();
                cnt++;
            }
        }return cnt;
    }
};