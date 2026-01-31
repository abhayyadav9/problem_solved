class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int current =1;
        int longest =1;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        if( n ==0) return n;

        for(int i =1; i<n ; i++){

            if(nums[i] == nums[i-1]){
                continue;
            }else if( nums[i] == nums[i-1] +1){
                current++;
            }else{

                longest = max(current, longest);
                current =1;

            }
        }
        

        return max(longest,current);
    }
};