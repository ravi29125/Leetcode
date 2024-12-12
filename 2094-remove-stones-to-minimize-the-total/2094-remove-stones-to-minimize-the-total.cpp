class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        long long ans=0;
        priority_queue<int> pq;
        for(int i:piles)pq.push(i);
        while(k--){
            int top=pq.top();pq.pop();
            pq.push(floor((top+1)/2));
        }
        while(!pq.empty()){
            ans+=pq.top();pq.pop();
        }return ans;
    }
};