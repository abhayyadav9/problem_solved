class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int m = start + (end - start) / 2;

            if (nums[m] < nums[m + 1]) {
                // peak is on the right
                start = m + 1;
            } else {
                // peak is on the left or at m
                end = m;
            }
        }
        return start;
    }
};
