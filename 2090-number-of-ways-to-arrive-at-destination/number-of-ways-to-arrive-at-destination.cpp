class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long MOD = 1e9 + 7;
        vector<vector<pair<int,long>>> adj(n);
        for (auto& r : roads) { adj[r[0]].push_back({r[1], r[2]}); adj[r[1]].push_back({r[0], r[2]}); }
        vector<long> dist(n, LONG_MAX), ways(n, 0);
        dist[0] = 0; ways[0] = 1;
        priority_queue<pair<long,int>, vector<pair<long,int>>, greater<>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto [v, w] : adj[u]) {
                if (d + w < dist[v]) { dist[v] = d + w; ways[v] = ways[u]; pq.push({dist[v], v}); }
                else if (d + w == dist[v]) ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
        return ways[n-1];
    }
};