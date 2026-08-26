class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> heap;
        unordered_map<char,int> freq;
        for(int i=0;i<s.size();i++) {
            freq[s[i]]++;
        }
        string ans;
        for(auto& [p,q] : freq) {
            heap.push({q,p});
        }
        
        while(!heap.empty()) {
            pair<int,char> p,q;
            p = heap.top();
            heap.pop();
            if(heap.empty() && p.first > 1) return ""; 
            else if (heap.empty() && p.first == 1) {
                ans.push_back(p.second);
                return ans;
            }
            q = heap.top();
            heap.pop();
            p.first--;
            ans.push_back(p.second);
            q.first--;
            ans.push_back(q.second);
            if(p.first>0) heap.push(p);
            if(q.first>0) heap.push(q);
        }

        return ans;
    }
};