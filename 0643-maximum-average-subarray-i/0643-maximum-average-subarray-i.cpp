class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double sum = 0;
        int start = 0;
        int end = 0;
        double maxAvrg = -1e18;

        while (end < nums.size()) {

            sum = sum + nums[end];

            if ((end - start + 1)< k) {

                end++;

            } else if ((end - start + 1) == k) {
         
                maxAvrg = max(maxAvrg,  double(sum / k));

                sum = sum - nums[start];
                start++;
                end++;
            }
        }

        return maxAvrg;
    }
};