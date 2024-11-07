class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int num=32;
        int ans=0;
        while(num--){
            int cnt=0;
            for(int &i:candidates){
                if(i%2==1)cnt++;
                i=i>>1;
            }
            ans=max(ans,cnt);
        }return ans;
    }
};