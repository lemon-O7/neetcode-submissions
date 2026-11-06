class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> queue;
        for(int i=0;i<gifts.size();i++) {
            queue.push(gifts[i]);
        }
        for(int i=0;i<k;i++) {
            long long temp = queue.top();
            queue.pop();
            temp = sqrt(temp);
            queue.push(temp);
        } 
        long long ans=0;
        while(!queue.empty()) {
            ans+=queue.top();
            queue.pop();
        }
        return ans;
    }
};