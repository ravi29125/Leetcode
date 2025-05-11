class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        set<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0)
            st.insert(nums[i]);
            mp[nums[i]].push_back(i);
        }
        int cnt=0;
        multiset<int> arr(mp[0].begin(),mp[0].end());
        for(int i:st){
            int m=mp[i].size();
            int curr=mp[i][0];
            //for(int j:arr)cout<<j<<" ";cout<<endl;
            for(int j=1;j<m;j++){
                auto it=arr.upper_bound(curr);
                //cout<<curr<<" ";cout<<(*it)<<" "<<mp[i][j]<<endl;
                if(it==arr.end()){
                    cnt++;
                    curr=-1;
                    break;
                }else if(*it < mp[i][j]){
                    cnt++;
                    curr=mp[i][j];
                }
            }
            if(curr!=-1)cnt++;
            //cout<<cnt<<endl;
            for(int j:mp[i])arr.insert(j);
        }return cnt;
    }
};