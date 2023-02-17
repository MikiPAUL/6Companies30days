#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int n = s.size(), req = (1 << k);
        for (int i = 0; i <= n - k; i++) {
            if (req - st.size() == 0) return true;
            else if (req - st.size() > n - i - k + 1) return false;
            st.insert(s.substr(i, k));
        }
        return st.size() == req;
    }
};

int main() {
    string s; int k; cin >> s >> k;

    Solution solve;
    cout << solve.hasAllCodes(s, k);
    return 0;
}