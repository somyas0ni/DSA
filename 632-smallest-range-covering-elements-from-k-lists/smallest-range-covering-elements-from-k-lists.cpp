class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        int curMax = INT_MIN;
        for (int i = 0; i < (int)nums.size(); i++) {
            pq.push({nums[i][0], i, 0}); curMax = max(curMax, nums[i][0]);
        }
        vector<int> best = {-100000, 100000};
        while (true) {
            auto [val, i, j] = pq.top(); pq.pop();
            if (curMax - val < best[1] - best[0]) best = {val, curMax};
            if (j + 1 == (int)nums[i].size()) break;
            int nxt = nums[i][j+1];
            curMax = max(curMax, nxt);
            pq.push({nxt, i, j+1});
        }
        return best;
    }
};