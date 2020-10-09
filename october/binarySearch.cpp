/*

Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. 
If target exists, then return its index, otherwise return -1.


Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4


Note:

You may assume that all elements in nums are unique.
n will be in the range [1, 10000].
The value of each element in nums will be in the range [-9999, 9999].
*/


//solution

class Solution {
public:
    
    int binSrch(vector<int>& arr,int a, int b,int n){
       if(b>=a){ 
        int mid = a +(b-a)/2;
        if(arr[mid]==n)return mid;
        if(arr[mid] < n){
            return binSrch(arr,mid+1,b,n);
        }
        return binSrch(arr,0,mid-1,n);
        }
        return -1;
        }
    int search(vector<int>& nums, int target) {
        return binSrch(nums,0, nums.size(),target);
    }
};