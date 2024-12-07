class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> s;
        for(int i:banned)s.insert(i);
        int cnt=0;
        for(int i=1;i<=n && maxSum>=i;i++){
            if(s.count(i)==0){
                maxSum-=i;
                cnt++;
            }
        }return cnt;
    }
};