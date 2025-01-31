class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int mx=0;
        for(int i:left){
            mx=max(mx,i);
        }
        for(int i:right){
            mx=max(mx,n-i);
        }return mx;
    }
};