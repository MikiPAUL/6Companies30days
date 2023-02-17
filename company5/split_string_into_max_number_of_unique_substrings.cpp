class Solution {
    set<string> st;

    int maxUniqueSplit(string s, int i){
        if(i == s.size()) {
            return st.size();
        }
        int ans = 0;

        for(int j = 1; j <= s.size()-i; j++){
            string curr = s.substr(i, j);
            if(st.find(curr) != st.end()) continue;
            st.insert(curr);
            ans = max(ans, maxUniqueSplit(s, i+j));
            st.erase(curr);
        }
        return ans;
    }
public:
    int maxUniqueSplit(string s) {
        return maxUniqueSplit(s, 0);
    }
};
