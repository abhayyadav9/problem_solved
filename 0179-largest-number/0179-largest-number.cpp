class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ans;

        for (int x : nums) {
            ans.push_back(to_string(x));
        }

        sort(ans.begin(), ans.end(), [](string& a, string& b) {
            return a + b > b + a;
        });

        if(ans[0] == "0") return "0";

        string result;
        for(string &s:ans){
            result+=s;
        }

        return result;
    }
};