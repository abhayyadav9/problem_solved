class Solution {
public:
    void cmb(vector<int>& candidates, int target,
             vector<vector<int>>& ans,
             vector<int>& cur,
             int index, int sum) {

        if (sum == target) {
            ans.push_back(cur);
            return;
        }

        if (sum > target || index >= candidates.size()) {
            return;
        }

        cur.push_back(candidates[index]);
        cmb(candidates, target, ans, cur, index, sum + candidates[index]);
        cur.pop_back();

        cmb(candidates, target, ans, cur, index + 1, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;

        cmb(candidates, target, ans, cur, 0, 0);
        return ans;
    }
};
