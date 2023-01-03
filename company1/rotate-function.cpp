#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<int> prefix(n), suffix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            ans += (i * nums[i]);
            prefix[i] = prefix[i - 1] + nums[i];
        }
        suffix[n - 1] = nums[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            suffix[j] = suffix[j + 1] + nums[j];
        }
        int start = n - 2, end = n, sum = ans;
        for (int i = 1; i < n; i++) {
            if (end != n) sum += suffix[end];
            sum -= (nums[start + 1] * (n - 1));
            sum += prefix[start--];
            ans = max(ans, sum);
            end--;
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