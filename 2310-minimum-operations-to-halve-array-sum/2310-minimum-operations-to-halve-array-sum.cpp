class Solution {
public:
    int halveArray(vector<int>& nums) {
        double ans=0,sum=0;
        priority_queue<float> pq;
        for(int i:nums)pq.push(i),ans+=i;
        sum=ans;
        int cnt=0;
        while(true){
            cnt++;
            float top=pq.top()/2;pq.pop();
            sum-=top;
            pq.push(top);
            if(sum<=(ans/2))break;
        }return cnt;
    }
};