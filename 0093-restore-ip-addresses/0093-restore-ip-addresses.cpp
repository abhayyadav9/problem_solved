class Solution {
public:
    void backtrack(string &s, int idx, int parts, string curr, vector<string> &ans) {
        // If 4 parts are formed and string is fully used
        if (parts == 4 && idx == s.size()) {
            ans.push_back(curr.substr(0, curr.size() - 1)); // remove last dot
            return;
        }

        // If parts exceed 4 or string ends early
        if (parts == 4 || idx == s.size()) return;

        // Try segments of length 1 to 3
        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string part = s.substr(idx, len);

            // Leading zero check
            if (part.size() > 1 && part[0] == '0') break;

            // Value check
            int val = stoi(part);
            if (val > 255) break;

            backtrack(s, idx + len, parts + 1, curr + part + ".", ans);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if (s.size() < 4 || s.size() > 12) return ans;

        backtrack(s, 0, 0, "", ans);
        return ans;
    }
};
