class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        map<int,int> mp;
        int n=x.size();
        for(int i=0;i<n;i++){
            if(mp.count(x[i])){
                if(y[i]>y[mp[x[i]]])mp[x[i]]=i;
            }else{
                mp[x[i]]=i;
            }
        }
        priority_queue<int,vector<int>,greater<>> pq;
        for(auto k:mp){
            pq.push(y[k.second]);
            if(pq.size()>3)pq.pop();
        }
        if(pq.size()<3)return -1;
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }return sum;
    }
};