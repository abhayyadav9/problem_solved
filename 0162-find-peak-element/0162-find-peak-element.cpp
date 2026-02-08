class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {

            int m = start + (end - start) / 2;

            if (nums[m] < nums[m + 1]) {
                start = m + 1;
            } else {
                end = m;
            }
        }
        return start;
    }
};