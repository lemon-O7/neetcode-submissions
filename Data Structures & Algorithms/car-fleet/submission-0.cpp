class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> times;
        int ans = 0;
        vector<pair<int,int>> cars; // {position, speed}
        for(int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        reverse(cars.begin(), cars.end());

        for(int i = 0;i<cars.size();i++) {
            float time = (float)(target - cars[i].first)/ cars[i].second;
            if(times.empty() || time>times.top()) {
                times.push(time);
                ans++;
            }
        }

        return ans;
    }
};