#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //if(is_sorted(nums.begin(), nums.end())) return 0;
        int n = nums.size();

        int large = 0, small = n - 1, start = -1, end = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[large]) {
                start = i;
            }
            else {
                large = i;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[small]) {
                end = i;
            }
            else {
                small = i;
            }
        }
        return start - end + 1;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);

    for (int& ele : nums) cin >> ele;

    Solution solve;
    cout << solve.findUnsortedSubarray(nums);
    return 0;
}