class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& nums) {
        priority_queue<long,vector<long>,greater<>> pq;
        unordered_set<long> st;
        pq.push(1);
        int ans=-1;
        while(n--){
            while(!pq.empty() && st.count(pq.top()))pq.pop();
            ans=pq.top();pq.pop();
            st.insert(ans);
            for(int i:nums)pq.push((long)i*ans);
        }
        return ans;
    }
};