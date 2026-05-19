class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> map;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp,value});       
    }
    
    string get(string key, int timestamp) {
        string result;
        int mid,high;
        int low =0;
        const auto &v = map[key];
        high=v.size()-1;
        
        while(low <= high){
            mid = low+(high-low)/2;
            if(v[mid].first<=timestamp) {
                result=v[mid].second;
                low=mid+1;
            }
            else {
                high = mid-1;
            }

        }

        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */