class NumArray {
    vector<int> nums;
public:
    NumArray(vector<int>& n) {
        this->nums=vector<int>(n.size()+1);
        for(int i=0;i<n.size();i++){
            nums[i+1]=nums[i]+n[i];
        }
    }
    
    int sumRange(int left, int right) {
        return nums[right+1]-nums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */