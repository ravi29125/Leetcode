class MyCalendar {
    vector<vector<int>> ls;
public:
    MyCalendar() {
        ls=vector<vector<int>>();
    }
    
    bool book(int start, int end) {
        for(auto k:ls){
            int l=k[0],r=k[1];
            if(l<start && start<r)return false;
            if(l<end && end<=r)return false;
            if(start<l && l<end)return false;
            if(start<r && r<=end)return false;
        }
        ls.push_back({start,end});
        //sort(ls.begin(),ls.end());
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */