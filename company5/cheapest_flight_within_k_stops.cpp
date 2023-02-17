class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n ,INT_MAX);
        dist[src] = 0;
        
        for(int i = 0; i <= k; i++){
            vector<int> temp(dist);
            for(auto& v: flights){
                if(dist[v[0]] == INT_MAX or dist[v[0]]+v[2] > temp[v[1]]) continue;
                temp[v[1]] = dist[v[0]]+v[2] ;
            }
            dist = temp;
        }
        return (dist[dst]==INT_MAX?-1:dist[dst]);
    }
};
