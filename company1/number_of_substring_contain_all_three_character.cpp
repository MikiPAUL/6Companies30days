#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> pos(3, -1);

        int ans = 0;
        int i = 0;
        for (char& c : s) {
            int min_pos = INT_MAX;
            for (int i = 0; i < 3; i++) {
                if (c - 'a' != i) {
                    min_pos = min(min_pos, pos[i]);
                }
            }
            if (min_pos != -1) {
                ans += min_pos + 1;
            }
            pos[c - 'a'] = i++;
        }
        return ans;
    }
};

int main() {
    string s; cin >> s;

    Solution solve;
    cout << solve.numberOfSubstrings(s);

    return 0;
}