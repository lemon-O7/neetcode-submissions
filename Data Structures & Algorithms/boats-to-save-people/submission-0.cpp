class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<bool> saved(people.size(),0);
        sort(people.begin(),people.end());

        int i,j;
        i=0;
        j=people.size()-1;

        int ans = 0;

        while(i<=j) {
            if(people[i]+people[j] <= limit) {
                i++;
                j--;
                ans++;
            }
            else {
                ans++;
                j--;
            }
        }

        return ans;
    }
};