class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        int start = 0;
        int end = mp[key].size()-1;
        string res = "";
        while(start <= end){
            int mid = start + (end - start) / 2;
            if((mp[key])[mid].second == timestamp){
                return (mp[key])[mid].first;
            } else if((mp[key])[mid].second < timestamp){
                res = (mp[key])[mid].first;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return res;
    }
};
