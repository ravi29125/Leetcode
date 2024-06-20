class Solution {
    vector<int> p;
    int m;
    bool help(int mid){
        int cnt=1;
        int prev=p[0];
        for(int i:p){
            if(i-prev >= mid){
                cnt++;
                prev=i;
            }
        }return cnt>=m;
    }
public:
    int maxDistance(vector<int>& p, int m) {
        int i=0;
        this->m=m;
        int n=p.size();
        sort(p.begin(),p.end());
        this->p=p;
        int j=p[n-1];
        int ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(help(mid)){
                ans=mid;
                i=mid+1;
            }else{
                j=mid-1;
            }
        }return ans;
    }
};