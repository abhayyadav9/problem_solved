class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {

        int n = arr.size();

        long long int totalSum = 0;
  
        for (int x : arr) {
      
            totalSum += x;
        }

        if(totalSum %3 != 0) return false;
   
     long long int currSum=0;;
     int count=0;

        for (int i = 0; i < n; i++) {
            currSum =  currSum + arr[i];

            if(currSum == totalSum/3){
                currSum=0;
                count++;

            }

        }

        return count >=3;
    }
};