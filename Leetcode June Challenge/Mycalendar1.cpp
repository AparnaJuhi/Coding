class MyCalendar {
public:
    vector<pair<int,int>>v;
    MyCalendar() {
        pair<int,int>p;
       v.push_back(p);
        
    }
    
    bool book(int start, int end) {
        for(int i=1;i<v.size();i++)
        {
            if(v[i].first<=start && v[i].second>start)
                return false;
            if(v[i].first<end && v[i].second>=end)
                return false;
            if(v[i].first>=start && v[i].second<=end)
                return false;
        }
        v.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
