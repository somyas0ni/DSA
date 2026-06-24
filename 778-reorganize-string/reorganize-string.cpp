class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> cnt;
        for (char c : s) cnt[c]++;
        priority_queue<pair<int,char>> pq;
        for (auto& [c, f] : cnt) {
            if (f > (int)(s.size() + 1) / 2) return "";
            pq.push({f, c});
        }
        string res;
        while (pq.size() >= 2) {
            auto [f1, c1] = pq.top(); pq.pop();
            auto [f2, c2] = pq.top(); pq.pop();
            res += c1; res += c2;
            if (--f1) pq.push({f1, c1});
            if (--f2) pq.push({f2, c2});
        }
        if (!pq.empty()) res += pq.top().second;
        return res;
    }
};