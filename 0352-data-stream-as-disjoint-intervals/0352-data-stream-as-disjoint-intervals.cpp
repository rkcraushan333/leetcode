class SummaryRanges {
public:
    set<int>s;
    SummaryRanges() {
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>res;
        int c = 0,past,k;
        for(auto i:s){
            if(!c){
                past = i;
                c = 1;
                k = i;
            }else{
                if(i!=past+1){
                    res.push_back({k,past});
                    k = i;
                    past = i;
                }else{
                    past = i;
                }
            }
        }
        res.push_back({k,past});
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */