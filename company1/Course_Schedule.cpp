#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> vis;
    vector<vector<int>> prereq;

    bool canFinishUtility(int i) {
        vis[i] = 1;
        bool is_finish = true;
        for (int pre : prereq[i]) {
            if (vis[pre] == 0) is_finish &= canFinishUtility(pre);
            else if (vis[pre] == 1) {
                is_finish = false;
                break;
            }
        }
        if (is_finish) vis[i] = 2;
        return is_finish;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vis.resize(n);
        prereq.resize(n);

        for (auto& vec : prerequisites) {
            prereq[vec[0]].push_back(vec[1]);
        }
        bool is_finish = true;

        for (int i = 0; i < n; i++) {
            is_finish &= canFinishUtility(i);
        }

        return is_finish;
    }
};

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> prerequisites(m, vector<int>(2, 0));

    for (auto& vec : prerequisites) {
        for (int& ele : vec) cin >> ele;
    }

    Solution solve;
    cout << solve.canFinish(n, prerequisites);

    return 0;
}