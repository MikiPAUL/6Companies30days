#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;

    void find(vector<int>& a, int k, int n, int j) {
        if (k == 0) {
            if (n == 0) ans.push_back(a);
            return;
        }
        for (int i = j; i < 10; i++) {
            if (n - i >= k - 1) {
                a.push_back(i);
                find(a, k - 1, n - i, i + 1);
                a.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        find(temp, k, n, 1);
        return ans;
    }
};

int main() {
    int k, n; cin >> k >> n;
    Solution solve;
    vector<vector<int>> ans = solve.combinationSum3(k, n);

    for (auto& vec : ans) {
        for (int ele : vec) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}