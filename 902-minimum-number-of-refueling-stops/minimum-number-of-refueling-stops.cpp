class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int fuel = startFuel, stops = 0, i = 0, n = stations.size();
        while (fuel < target) {
            while (i < n && stations[i][0] <= fuel) pq.push(stations[i++][1]);
            if (pq.empty()) return -1;
            fuel += pq.top(); pq.pop(); stops++;
        }
        return stops;
    }
};