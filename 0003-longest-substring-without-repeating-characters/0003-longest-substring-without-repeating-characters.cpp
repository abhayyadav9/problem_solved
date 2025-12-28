class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char>st;
        int n = s.size();
        int longest=0;
        int start =0, end = 0;

        while(end <n){

            if(st.find(s[end]) == st.end()){
                st.insert(s[end]);
                longest = max(longest , end- start +1);
                end++;

            }else{
                st.erase(s[start]);
                start++;
            }
        }

        return longest;
        
    }
};