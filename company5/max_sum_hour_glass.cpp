class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<long long>> prefix(n, vector<long long>(m, 0));

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                prefix[i][j] = grid[i][j];
            }
        }

        for(int i = 0; i < grid.size(); i++){
            for(int j = 1; j < grid[0].size(); j++){
                prefix[i][j] += prefix[i][j-1];
            }
        }
        for(int i = 0; i < grid[0].size(); i++){
            for(int j = 1; j < grid.size(); j++){
                prefix[j][i] += prefix[j-1][i];
            }
        }

        long long ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(i-2 < 0 or j-2 < 0) continue;
                long long curr = prefix[i][j] - grid[i-1][j] - grid[i-1][j-2];
                if(i-3 >= 0) curr -= prefix[i-3][j];
                if(j-3 >= 0) curr -= prefix[i][j-3];
                if(i-3 >= 0 and j-3 >= 0) curr += prefix[i-3][j-3];
                ans = max(curr, ans);
            }
        }
        return ans;
    }
};
