class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (n > m) return "";

        unordered_map<char, int> mp;
        for (char c : t) mp[c]++;

        int required = mp.size();   // unique chars needed
        int formed = 0;

        unordered_map<char, int> window;

        int left = 0, right = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (right < m) {
            char c = s[right];
            window[c]++;

            if (mp.count(c) && window[c] == mp[c]) {
                formed++;
            }

            // Try shrinking
            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char d = s[left];
                window[d]--;

                if (mp.count(d) && window[d] < mp[d]) {
                    formed--;
                }
                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
