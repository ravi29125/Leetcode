class Solution {
public:
    int shortestSequence(vector<int>& nums, int k) {
        int n=nums.size();
        int c=1;
        unordered_set<int> st;
        vector<int> arr(n,-1);
        for(int i=n-1;i>-1;i--){
            arr[i]=c;
            st.insert(nums[i]);
            if(st.size()==k){
                c++;
                st.clear();
            }
        }
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            if(arr[i]==arr[0]){
                s.insert(nums[i]);
            }else break;
        }
        //for(int i:arr)cout<<i<<" ";
        for(int i=1;i<=k;i++){
            if(s.count(i)==0)return arr[0];
        }return arr[0]+1;
    }
};