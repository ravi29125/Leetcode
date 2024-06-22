class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> mul;
        int i=0;
        int j=0;
        int n=nums.size();
        vector<int> arr;
        int p=k;
        while(k--)mul.insert(nums[j++]);
        //cout<<j<<endl;
        while(j<n){
            auto it=mul.rbegin();
            //cout<<*it<<" ";
            arr.push_back(*it);
            mul.erase(mul.find(nums[i++]));
            mul.insert(nums[j++]);
        }
        arr.push_back(*mul.rbegin());
        //cout<<*mul.rbegin()<<" ";
        return arr;
    }
};