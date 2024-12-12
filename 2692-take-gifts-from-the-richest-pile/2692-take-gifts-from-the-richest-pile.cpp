class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;
        priority_queue<int> pq;
        for(int i:gifts)pq.push(i);
        while(k--){
            int top=pq.top();pq.pop();
            pq.push(sqrt(top));
        }
        while(!pq.empty()){
            ans+=pq.top();pq.pop();
        }return ans;
    }
};