class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        if (words.empty() || s.empty()) return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int windowLen = wordLen * wordCount;

        unordered_map<string, int> wordMap;

        // ✅ Store frequency of each word
        for (auto &w : words) {
            wordMap[w]++;
        }

        // ✅ Slide window across the string
        for (int i = 0; i < wordLen; i++) {

            unordered_map<string, int> seen;
            int left = i;
            int count = 0;

            for (int right = i; right + wordLen <= s.size(); right += wordLen) {

                string word = s.substr(right, wordLen);

                // ✅ If word exists in our list
                if (wordMap.count(word)) {
                    seen[word]++;
                    count++;

                    // ✅ If frequency exceeded, shrink window
                    while (seen[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // ✅ If all words matched
                    if (count == wordCount) {
                        ans.push_back(left);
                    }

                } else {
                    // ❌ Invalid word → Reset window
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};
