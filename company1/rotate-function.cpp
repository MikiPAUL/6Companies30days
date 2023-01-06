#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = 0, n = nums.size(), temp = 0;
        int sum = accumulate(begin(nums), end(nums), 0);

        for (int i = 0; i < n; i++) {
            ans += i * nums[i];
        }
        temp = ans;
        for (int i = n - 1; i >= 0; i--) {
            temp += sum - nums[i] * n;
            ans = max(ans, temp);
        }
        return ans;
    }
};


int main() {
    int n; cin >> n;
    vector<int> arr(n);

    for (int& ele : arr) cin >> ele;

    Solution solve;
    cout << solve.maxRotateFunction(arr);

    return 0;
}