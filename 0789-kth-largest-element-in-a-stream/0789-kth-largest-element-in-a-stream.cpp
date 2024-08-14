class KthLargest {
    multiset<int> mul;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i:nums)mul.insert(i);
        this->k=k;
    }
    int add(int val) {
        mul.insert(val);
        int n=mul.size()-k;
        auto it=mul.begin();
        advance(it,n);
        return *it;   
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */