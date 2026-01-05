class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();

        int smallest=1;

        for(int i =0; i<n; i++){

            if(nums[i] <smallest) continue;
            if(nums[i] ==smallest) smallest++;
            else if(nums[i] >smallest) return smallest;
        }

        return smallest;
        
    }
};