class Twitter {
private:
    unordered_map<int, unordered_set<int>> followMap;
    vector<pair<int, int>> posts;
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        this->posts.push_back(make_pair(userId, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        int count = 10;
        vector<int> feed;
        for(int i = posts.size() - 1; i >= 0 && count > 0; i--) {
            int postUserId = posts[i].first;
            int tweetId = posts[i].second;
            
            if(followMap[userId].find(postUserId) != followMap[userId].end() || userId == postUserId) {
                feed.push_back(tweetId);
                count--;
            }
        }
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
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