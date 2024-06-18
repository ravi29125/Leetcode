class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> pq;
        int n=d.size();
        for(int i=0;i<n;i++){
            pq.push({d[i],p[i]});
        }
        sort(w.begin(),w.end());
        int sum=0;
        int mx=0;
        for(int i:w){
            while(!pq.empty() && i>=pq.top().first){
                //cout<<pq.top().second<<" ";
                mx=max(mx,pq.top().second);pq.pop();
            }sum+=mx;
        }
        //cout<<pq.size();
        return sum;
    }
};