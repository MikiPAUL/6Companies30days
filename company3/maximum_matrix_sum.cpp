class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        #define ll long long
        ll min_ele = INT_MAX, cnt = 0, sum = 0;

        for(auto& vec: matrix){
            for(int& ele: vec){
                sum += abs(ele);
                min_ele = min(min_ele, 1ll*abs(ele));
                if(ele < 0){
                    cnt++;
                    continue;
                }
            }
        }
        if(cnt%2 == 0) return sum;
        return sum - 2*min_ele;
    }
};
