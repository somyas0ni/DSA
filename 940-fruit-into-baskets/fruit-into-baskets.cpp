class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> cnt;
        int l = 0, best = 0;
        for (int r = 0; r < (int)fruits.size(); r++) {
            cnt[fruits[r]]++;
            while (cnt.size() > 2) { if (--cnt[fruits[l]] == 0) cnt.erase(fruits[l]); l++; }
            best = max(best, r - l + 1);
        }
        return best;
    }
};