class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        const int MOD = 1e9 + 7;

        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;

        // Handle zeros separately
        int zeroCount = freq[0];
        freq.erase(0);

        vector<int> dp(r + 1, 0);
        dp[0] = 1;

        for (auto &[val, cnt] : freq) {
            vector<int> newdp(r + 1, 0);

            for (int rem = 0; rem < val; rem++) {
                long long windowSum = 0;

                for (int s = rem; s <= r; s += val) {
                    windowSum = (windowSum + dp[s]) % MOD;

                    int out = s - val * (cnt + 1);
                    if (out >= 0) {
                        windowSum = (windowSum - dp[out] + MOD) % MOD;
                    }

                    newdp[s] = windowSum;
                }
            }
            dp.swap(newdp);
        }

        // Multiply ways by (zeroCount + 1)
        long long zeroWays = zeroCount + 1;
        for (int s = 0; s <= r; s++) {
            dp[s] = (dp[s] * zeroWays) % MOD;
        }

        long long ans = 0;
        for (int s = l; s <= r; s++) {
            ans = (ans + dp[s]) % MOD;
        }
        return ans;
    }
};
