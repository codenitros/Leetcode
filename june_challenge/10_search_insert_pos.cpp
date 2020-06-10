/*

Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2

*/

//solution

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0,high = nums.size()-1;
        int mid;
        if(target <= nums[0])
        {
            return 0;
        }
        else if(target > nums[nums.size()-1])
        {
            return nums.size();
        }
        while(low <= high)
        {
            mid  = low + (high - low)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        if(mid!=0 && nums[mid-1] < target && nums[mid] >= target){
            return mid;
        }
        else
        {
            return mid+1;
        }
        
    }
};