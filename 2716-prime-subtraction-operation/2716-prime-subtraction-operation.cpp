class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n=1001;
        vector<bool> arr(n,false);
        //arr[1]=arr[0]=false;
        for(int i=2;i<n;i++){
            for(int j=2;i*j<n;j++){
                arr[i*j]=true;
            }
        }
        vector<int> prime;
        for(int i=2;i<n;i++){
            if(!arr[i])prime.push_back(i);
        }
        //for(int i:prime)cout<<i<<" ";
        for(int i=nums.size()-2;i>-1;i--){
            if(nums[i]<nums[i+1])continue;
            else{
                for(int p:prime){
                    if(p>=nums[i])break;
                    if((nums[i]-p)<nums[i+1]){
                        nums[i]-=p;
                        break;
                    }
                }
                if(nums[i]>=nums[i+1])return false;
            }
        }
        //for(int i:nums)cout<<i<<" ";
        return true;
    }
};