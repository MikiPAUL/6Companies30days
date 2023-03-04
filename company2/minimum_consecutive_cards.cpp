class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> lastPos;
        int n = cards.size(), ans = INT_MAX;

        for(int i = 0; i < cards.size(); i++){
            if(lastPos.count(cards[i])){
                ans = min(ans, i-lastPos[cards[i]]+1);
            }
            lastPos[cards[i]] = i;
        }
        return (ans == INT_MAX? -1: ans);
    }
};
