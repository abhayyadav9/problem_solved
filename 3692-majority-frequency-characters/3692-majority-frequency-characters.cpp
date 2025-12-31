class Solution {
public:
    string majorityFrequencyGroup(string s) {

        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // frequency -> list of characters
        unordered_map<int, vector<char>> groups;
        for (auto &p : freq) {
            groups[p.second].push_back(p.first);
        }

        int bestFreq = 0;
        int bestSize = 0;

        for (auto &g : groups) {
            int k = g.first;
            int size = g.second.size();

            if (size > bestSize || (size == bestSize && k > bestFreq)) {
                bestSize = size;
                bestFreq = k;
            }
        }

        string result = "";
        for (char c : groups[bestFreq]) {
            result.push_back(c);
        }

        return result;
    }
};
