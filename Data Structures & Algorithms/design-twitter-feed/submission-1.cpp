class Twitter {
public:
    int timestamp=0;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int,int>>> tweets;
   
    Twitter() {       
        
    }
    
    void postTweet(int userId, int tweetId) {
        timestamp++;
        tweets[userId].push_back({timestamp,tweetId});

    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> feedheap;
        for(int i=0;i<tweets[userId].size();i++) {
        feedheap.push(tweets[userId][i]);
        }
        for(int followeeId : following[userId]) {
            if(followeeId == userId) continue;
            for(int j=0;j<tweets[followeeId].size();j++) {
                feedheap.push(tweets[followeeId][j]);
            }
        }
        vector<int> feed;
        for(int i=0;i<10;i++) {
            if(feedheap.empty()) break;
            feed.push_back(feedheap.top().second);
            feedheap.pop();
        }
        return feed;

    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */