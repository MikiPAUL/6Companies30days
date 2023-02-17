class Solution {

public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int ans = 0, i = 0;
        for(; i < fruits.size(); i++) {
            mp[fruits[i]]++;
            if(mp.size() > 2) break;
        }
        ans = i;
        int start = 0;
        for(; ; ){
            if(mp.size() > 2){
                if(--mp[fruits[start]] == 0) mp.erase(fruits[start]);
                start++;
            }
            if(++i >= fruits.size()) break;
            mp[fruits[i]]++;
            if(mp.size() <= 2) ans = i-start+1;
        }
        return ans;
    }
};
