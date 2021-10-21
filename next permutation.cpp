/* ALGORITHM 
  1. find first index from right such that nums[index] < nums[index + 1] ... label this index as idx1
  2. find first index from right such that nums[index] > nums[idx1] .. label this index as idx2
  3. swap(nums[idx1],nums[idx2])
  4. reverse the array nums[idx1 + 1 ... sz)
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int prev = -1;
        int idx1 = -1;
        int idx2 = -1;
        int sz = nums.size();
        for(int i = sz - 1 ; i >= 0 ; i--) {
            if(nums[i] < prev) {
                idx1 = i;
                break;
            }
            prev = nums[i];
        }
        
        if(idx1 == -1) {
            sort(begin(nums),end(nums));
            return;
        }
        
        for(int i = sz - 1 ; i > idx1 ; i--) {
            if(nums[i] > nums[idx1]) {
                idx2 = i;
                break;
            }
        }
        
        swap(nums[idx1],nums[idx2]);
        
        reverse(begin(nums) + idx1 + 1,end(nums));
    }
};
