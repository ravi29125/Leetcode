class Solution {
    int help(int k){
        int cnt=0;
        while(k>1){
            cnt++;
            if(k%2==0){
                k/=2;
            }else{
                k*=3;
                k++;
            }
            int val=__builtin_popcount(k);
            if(val==1)break;
        }return cnt+log2(k);
    }
public:
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=lo;i<=hi;i++){
            int val=help(i);
            pq.push({val,i});
            if(pq.size()>k)pq.pop();
        }return pq.top().second;
    }
};