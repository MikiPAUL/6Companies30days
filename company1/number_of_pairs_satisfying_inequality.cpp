#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long int merge(long long arr[], int start, int mid, int end, int diff) {
        int a = mid - start + 1, b = end - mid;
        vector<long long> x(arr + start, arr + mid + 1), y(arr + mid + 1, arr + end + 1);
        long long int ans = 0;

        int j = 0;

        for (int i = 0; i < a and j < b; i++) {
            while (j < b and x[i] > y[j] + diff) j++;
            if (j == b) break;
            ans += (b - j);
        }

        int i = 0;
        j = 0;
        while (i < a or j < b) {
            if (i < a and j < b) {
                if (x[i] <= y[j]) {
                    arr[start] = x[i++];
                }
                else {
                    arr[start] = y[j++];
                }
            }
            else if (i < a) {
                arr[start] = x[i++];
            }
            else {
                arr[start] = y[j++];
            }
            start++;
        }

        return ans;
    }
    long long int merge_sort(long long arr[], int start, int end, int diff) {
        if (start < end) {
            long long int mid = start + (end - start) / 2, ans = 0;
            ans += merge_sort(arr, start, mid, diff);
            ans += merge_sort(arr, mid + 1, end, diff);
            ans += merge(arr, start, mid, end, diff);
            return ans;
        }
        return 0;
    }
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        long long arr[n];

        for (int i = 0; i < n; i++) {
            arr[i] = nums1[i] - nums2[i];
        }
        return merge_sort(arr, 0, n - 1, diff);
    }
};

int main() {
    int n, diff; cin >> n >> diff;
    vector<int> a(n), b(n);

    for (auto& ele : a) cin >> ele;
    for (auto& ele : b) cin >> ele;

    Solution solve;
    cout << solve.numberOfPairs(a, b, diff);
    return 0;
}