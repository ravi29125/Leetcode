class Solution {
    vector<int> bl;
    int m;
    int k;
    bool isSafe(int mid){
        int cnt=0;
        int val=0;
        for(int i:bl){
            if(i<=mid){
                cnt++;
            }else{
                cnt=0;
            }
            if(cnt==k){
                val++;
                cnt=0;
            }
        }return val>=m;
    }
public:
    int minDays(vector<int>& b, int m, int k) {
        this->m=m;
        this->k=k;
        this->bl=b;
        int l=0;
        int r=*max_element(b.begin(),b.end());
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isSafe(mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }return ans;
    }
};