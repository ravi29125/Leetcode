class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        int j=0;
        vector<int> ans(queries.size(),0);
        for(auto i:queries){
            pq.push(abs(i[0])+abs(i[1]));
            if(pq.size()>k){
                pq.pop();
            }
            if(pq.size()<k){
                ans[j++]=-1;
            }else{
                ans[j++]=pq.top();
            }
        }return ans;
    }
};