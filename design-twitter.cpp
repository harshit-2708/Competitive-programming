class User{
    public:
        int id;
        set<int> follow;
        User(int use){
            id=use;
            follow.insert(use);
        }
};
class Twitter {
    unordered_map<int,User*> a;
    vector<pair<int,int>> post;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if(a.find(userId)==a.end()){
            User *b=new User(userId);
            a[userId]=b;
        }
        post.push_back(make_pair(userId,tweetId));
    }

    vector<int> getNewsFeed(int userId) {
        if(a.find(userId)==a.end()){
            User *b=new User(userId);
            a[userId]=b;
            vector<int> c;
            return c;
        }
        set<int> b=a[userId]->follow;
        vector<int> c;
        int i=0,j=post.size()-1;
        while(i<10&&j>=0){
            if(b.find(post[j].first)!=b.end()){
                c.push_back(post[j].second);
                i++;
            }
            j--;
        }
        return c;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId){
            return;
        }
        if(a.find(followerId)==a.end()){
            User *b=new User(followerId);
            a[followerId]=b;
        }
        if(a.find(followeeId)==a.end()){
            User *b=new User(followeeId);
            a[followeeId]=b;
        }
        a[followerId]->follow.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId){
            return;
        }
        if(a.find(followerId)==a.end()){
            User *b=new User(followerId);
            a[followerId]=b;
        }
        if(a.find(followeeId)==a.end()){
            User *b=new User(followeeId);
            a[followeeId]=b;
            return;
        }
        a[followerId]->follow.erase(followeeId);
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
