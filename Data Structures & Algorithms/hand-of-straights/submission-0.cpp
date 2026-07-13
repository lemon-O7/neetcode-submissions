class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> freq;
        sort(hand.begin(),hand.end());
        for(int i=0;i<hand.size();i++) {
            freq[hand[i]]++;
        }
        if(hand.size()%groupSize!=0) return false;

        for(auto& [key,count] : freq) {
            if(count>0) {
                int times = count;
                for(int j=0;j<groupSize;j++) {
                    freq[key+j]-=times;
                    if(freq[key+j]<0) return false;
                }
            }
        }
        return true;
    }
};