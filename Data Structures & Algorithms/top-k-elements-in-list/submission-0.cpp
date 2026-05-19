class Solution {
public:
    int MaxFreq(unordered_map<int,int> x){
        int maxvalue= INT_MIN,key=INT_MIN;
        if(x.empty()) {
            return 0;
        }
        for(auto& p: x) {
            if(p.second > maxvalue) {
                maxvalue=p.second;
                key=p.first;
            }
        }
        return key;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counting;
        for(int i=0;i<nums.size();i++) {
           counting[nums[i]]++;
        }
        for(auto& p: counting) {
            cout<<p.first<<" "<<p.second<<endl;
        }
        vector<int> result={};
        for(int i=0;i<k;i++) {
            result.push_back(MaxFreq(counting));
            counting.erase(result[i]);
        }
        
        return result;
    }
};
