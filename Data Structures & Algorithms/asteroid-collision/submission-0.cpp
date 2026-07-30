class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n = asteroids.size();
        for(int i=0;i<n;i++) {
            if(asteroids[i]>0) {
                s.push(asteroids[i]);
            }
            else {
                bool destroyed = false;
                while(!s.empty() && s.top() >0) {
                    if(abs(asteroids[i])>s.top()) {
                        s.pop();
                    }
                    else if (abs(asteroids[i])<s.top()) {
                        destroyed = true;
                        break;
                    }
                    else {
                        s.pop();
                        destroyed = true;
                        break;
                    }
                }
                if(!destroyed == true) s.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};