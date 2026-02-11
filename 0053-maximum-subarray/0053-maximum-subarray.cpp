// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int maxSum=INT_MIN;
//         if(n==1) return nums[0];

//         for(int i =0; i<n ; i++){
//             int sum =nums[i];
//             maxSum = max(maxSum, sum);


//             for(int j =i+1; j<n; j++){
//                 sum +=nums[j];
//                 maxSum = max(maxSum, sum);


//             }
//         }

//         return maxSum;
        
//     }
// };


//now optimizing the time complexcity of the algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        long long int maxSum = INT_MIN;
        long long int currSum =0;

        int start=0;
        int end =0;

        for(int i =0; i<n; i++){

            currSum = currSum + nums[i];

            maxSum = max(currSum,maxSum);

            if(currSum<0){
                currSum =0;
            }
        }

        return maxSum;
        
    }
};