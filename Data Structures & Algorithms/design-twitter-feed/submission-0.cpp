class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;

        vector<pair<int,int>>& owntweets = tweets[userId];
        int n = owntweets.size();

        for(int i = max(0, n-10); i < n; i++){
            pq.push(owntweets[i]);
        }

        for(int followeeId : following[userId]){
            vector<pair<int,int>>& theirtweets = tweets[followeeId];
            int m = theirtweets.size();
            for(int i = max(0, m-10); i < m; i++){
                pq.push(theirtweets[i]);
            }
        }

        vector<int> result;
        int count = 0;

        while(!pq.empty() && count < 10){
            result.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
private:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int timestamp = 0;
};