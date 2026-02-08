// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         int n = nums.size();

//         for(int i =1; i<n ; i++){
//             if(nums[i -1] == nums[i] ){
//                 return nums[i];
//             }
//         }
//         return 0;
        
//     }
// };


//optimize way using the floyds algo


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow= nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow !=fast);

        slow = nums[0];

        while(slow != fast){
            slow= nums[slow];
            fast = nums[fast];
        }


        return slow;
        
    }
};