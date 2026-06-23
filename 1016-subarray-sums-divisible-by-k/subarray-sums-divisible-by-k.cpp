class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> cnt(k, 0); cnt[0] = 1;
        int sum = 0, ans = 0;
        for (int x : nums) {
            sum = ((sum + x) % k + k) % k;
            ans += cnt[sum]++;
        }
        return ans;
    }
};