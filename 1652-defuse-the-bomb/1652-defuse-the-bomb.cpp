class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int start = 0;
        int end = 0;
        int n = code.size();

        long sum = 0;

        vector<int> result(n, 0);
        if (k == 0)
            return result;

        if (k > 0) {
            start = 1;
            end= k;
        } else {
            start = n + k;
            end = n - 1;
        }

        for (int i = start; i <= end; i++) {
            sum += code[i % n];
        }

        for (int i = 0; i < n; i++) {
            result[i] = sum;

            sum = sum - code[start % n];
            start++;
            end++;
            sum += code[end % n];
        }

        return result;
    }
};