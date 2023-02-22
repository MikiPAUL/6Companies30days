class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);

        for(int i = 0; i < s.size(); i++){
            pos[s[i]-'a'].push_back(i);
        }
        int ans = 0;
        for(string& word: words){
            int last = -1;
            bool flag = true;
            for(char c: word){
                auto loc = upper_bound(pos[c-'a'].begin(), pos[c-'a'].end(), last);
                if(loc == pos[c-'a'].end()){
                    flag = false;
                    break;
                }
                last = *loc;
            }
            if(flag) ans++;
        }
        return ans;
    }
};
