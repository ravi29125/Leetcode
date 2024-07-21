class Solution {
public:
    int minChanges(int n, int k) {
        int cnt=0;
        while(n>0 || k>0){
            if(n%2==0 && 1==k%2)return -1;
            if(n%2!=k%2)cnt++;
            if(n>0)
            n=n>>1;
            if(k>0)
            k=k>>1;
        }return cnt;
    }
};