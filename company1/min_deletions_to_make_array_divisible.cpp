#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int res = numsDivide[0];

        for (int ele : numsDivide) {
            res = __gcd(res, ele);
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (res % nums[i] == 0) return i;
        }
        return -1;
    }
};


int main() {
    int n, m; cin >> n >> m;
    vector<int> nums(n), numsDivide(m);

    for (int& ele : nums) cin >> ele;
    for (int& ele : numsDivide) cin >> ele;

    Solution solve;
    cout << solve.minOperations(nums, numsDivide);
    return 0;
}