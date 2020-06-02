
/*
You are given a sorted array consisting of only integers where every element appears exactly twice,
 except for one element which appears exactly once. Find this single element that appears only once.

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
*/



//solution


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // binary search approach
        // 3 3 7 7 10 11 11
        
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int beg=0, end=nums.size()-1;
        while(beg<end)
        {
            // avoiding overflow
            int mid = beg + (end - beg)/2;
            //base case
            if(mid == 0 || mid == nums.size()-1 || (nums[mid-1] != nums[mid] && nums[mid+1] != nums[mid]))
               return nums[mid];
            
            // 2 cases where mid can be both odd/even
            if(nums[mid-1] == nums[mid] && (mid)%2!=0 )
                beg = mid+1; 
            else if(nums[mid+1] == nums[mid]  && mid%2==0)
                beg = mid+1;
            else
                end = mid;
        }
        return nums[beg];
    }
};