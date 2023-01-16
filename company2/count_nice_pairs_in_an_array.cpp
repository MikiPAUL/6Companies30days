#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = 1e9 + 7;
    int rev(int ele) {
        int n = 0;

        while (ele) {
            n *= 10;
            n += ele % 10;
            ele /= 10;
        }
        return n;
    }
public:
    int countNicePairs(vector<int>& nums) {
        map<int, int> mp;
        int ans = 0;
        for (int ele : nums) {
            int curr = ele - rev(ele);
            ans = (ans + mp[curr]) % mod;
            mp[curr] = (mp[curr] + 1) % mod;
        }
        return ans;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);

    for (int& ele : nums) cin >> ele;
    Solution solve;
    cout << solve.countNicePairs(nums);
    return 0;
}