#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)

class Solution {
    vector<int> dp;
    vector<int> ans;

    int find(vector<int>& a, int last = INT_MIN) {
        int n = a.size();
        rforn(i, n - 1) {
            dp[i] = 1;
            forsn(j, i + 1, n) {
                if (a[j] % a[i] == 0) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        int ans = 0;
        for (int ele : dp) ans = max(ans, ele);
        return ans;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        dp.resize(n, -1);
        int lds_count = find(nums, 0), last = 1;
        for (int i = 0; i < n; i++) {
            if (dp[i] == lds_count and nums[i] % last == 0) {
                ans.push_back(nums[i]);
                last = nums[i];
                lds_count--;
            }
        }

        return ans;
    }
};

int main() {
    int n; cin >> n;
    vector<int> a(n);

    for (int& ele : a) cin >> ele;

    Solution solve;
    auto ans = solve.largestDivisibleSubset(a);

    for (int ele : ans) cout << ele << " ";

    return 0;
}