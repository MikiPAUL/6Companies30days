#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> pos(26, -1);

        for (int i = 0; i < order.size(); i++) {
            pos[order[i] - 'a'] = i;
        }
        sort(begin(s), end(s), [&](const char& a, const char& b) {
            return pos[a - 'a'] < pos[b - 'a'];
        });
        return s;
    }
};

int main() {
    string order, s; cin >> order >> s;

    Solution solve;
    cout << solve.customSortString(order, s);
    return 0;
}