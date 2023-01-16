#include <bits/stdc++.h>
using namespace std;

class Solution {
    string prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return s.substr(0, pi[n - 1]);
    }
public:
    string longestPrefix(string s) {
        return prefix_function(s);
    }
};

int main() {
    string s; cin >> s;

    Solution solve;
    cout << solve.longestPrefix(s);
    return 0;
}