class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> s;
        int mx=0,n=h.size();
        for(int i=0;i<=n;i++){
            while(!s.empty() &&(i==n || h[s.top()]>=h[i])){
                int val=s.top();s.pop();
                int w;
                if(s.empty())w=i;
                else w=i-s.top()-1;
                mx=max(mx,w*h[val]);
            }
            s.push(i);
        }return mx;
    }
};