class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int c=0,n=arr.size();
        for(int i:arr){
            if(i&1)c++;
            else c=0;
            if(c==3)return true;
        }return false;
    }
};