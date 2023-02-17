class TweetCounts {
    map<string, multiset<int>> tweetNameToTimeList;
    map<string, int> timeChunks;
public:
    TweetCounts() {
        timeChunks = {{"minute", 60}, {"hour", 3600}, {"day", 86400}};
    }
    
    void recordTweet(string tweetName, int time) {
        tweetNameToTimeList[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        
        int time = timeChunks[freq], nxt, currFreq = 0;
        nxt = startTime + time;
        int no = (endTime-startTime+time)/time;
        vector<int> occurence(no, 0);
        for(int occ: tweetNameToTimeList[tweetName]){
            if(occ > endTime) break;
            occ -= startTime;
            if(occ >= 0){
                occurence[occ/time]++;
            }
        }
        return occurence;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
