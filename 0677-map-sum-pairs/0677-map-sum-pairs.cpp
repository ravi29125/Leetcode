class MapSum {
    unordered_map<string,int> mp;
public:
    MapSum() {
        mp.clear();
    }
    
    void insert(string key, int val) {
        mp[key]=val;   
    }
    
    int sum(string prefix) {
        int res=0;
        for(auto k:mp){
            if(k.first.find(prefix)==0)res+=k.second;
        }return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */