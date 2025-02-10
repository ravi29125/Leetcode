class Solution {
public:
    int minDeletion(vector<int>& nums) {
        stack<int> s;
        int cnt=0;
        for(int i:nums){
            if(s.empty()){
                s.push(i);
            }else if(s.top()==i){
                cnt++;
            }else{
                s.pop();
            }
        }return cnt+s.size();
    }
};