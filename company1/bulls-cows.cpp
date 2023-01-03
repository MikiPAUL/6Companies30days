#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int cow = 0, bull = 0;
        vector<int> mp(10, 0);

        for (int i = 0; i < guess.size(); i++) {
            if (secret[i] == guess[i]) bull++;
            else mp[guess[i] - '0']++;
        }
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) continue;
            if (mp[secret[i] - '0'] > 0) {
                cow++;
                mp[secret[i] - '0']--;
            }
        }
        string ans = to_string(bull) + "A" + to_string(cow) + "B";
        return ans;
    }
};

int main() {
    string secret, guess; cin >> secret >> guess;

    Solution solve;
    cout << solve.getHint(secret, guess);

    return 0;
}