// class Solution {
// public:
//     int numOfSubarrays(vector<int>& arr) {

//         vector<vector<int>> ans;

//         int n = arr.size();
//         int count = 0;

//         for (int i = 0; i < n; i++) {
//             long long sum = arr[i];

//             if (sum % 2 == 1) {

//                 count++;
//             }

//             for (int j = i + 1; j < n; j++) {
//                 sum = sum + arr[j];

//                 if (sum % 2 == 1) {

//                     count++;
//                 }
//             }
//         }

//         long long m = ans.size();
//         return count;
//     }
// };




//reducing the tme complexity
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

    const int MOD = 1e9 +7;


        long long sum =0;
        int count = 0;
        int even =1, odd =0;

        for(int i :arr){
            sum = sum + i;
            if(sum %2 ==1){

                count = (count + even) % MOD;
                odd++;
            }else{
                count = ( count+odd) %MOD;
                even++;
            }
        }

  
        return count;
    }
};