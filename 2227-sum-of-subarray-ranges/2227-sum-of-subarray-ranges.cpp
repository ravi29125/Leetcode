class Solution {
    long long sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long ans=0,q,w,e;
        vector<int> forward(n,-1),backward(n,n);
        stack<int>one,two;
        for(int i=0;i<n;i++){
            while(!one.empty() && arr[i]<arr[one.top()])one.pop();
            forward[i]=(one.empty())?-1:one.top();
            one.push(i);
        }for(int i=n-1;i>-1;i--){
            while(!two.empty() && arr[i]<=arr[two.top()]) two.pop();
            backward[i]=(two.empty())?n:two.top();
            two.push(i);
        }for(int i=0;i<n;i++){
            q=((long long)arr[i]*(i-forward[i]));
            w=(q*(backward[i]-i));
            ans = (ans+w);
        }return ans;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n=arr.size();
        long long ans=0,q,w,e;
        vector<int> forward(n,-1),backward(n,n);
        stack<int>one,two;
        for(int i=0;i<n;i++){
            while(!one.empty() && arr[i]>arr[one.top()])one.pop();
            forward[i]=(one.empty())?-1:one.top();
            one.push(i);
        }for(int i=n-1;i>-1;i--){
            while(!two.empty() && arr[i]>=arr[two.top()]) two.pop();
            backward[i]=(two.empty())?n:two.top();
            two.push(i);
        }for(int i=0;i<n;i++){
            q=((long long)arr[i]*(i-forward[i]));
            w=(q*(backward[i]-i));
            ans = (ans+w);
        }return ans;
    }
public:
    long long subArrayRanges(vector<int>& arr) {
        int mod=1e9+7;
        return sumSubarrayMaxs(arr)-sumSubarrayMins(arr);
    }
};