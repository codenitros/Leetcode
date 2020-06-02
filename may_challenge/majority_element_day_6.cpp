/*

Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3

*/

//soultion

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int,int> store;
        for(int i=0;i<nums.size();i++)
        {
            store[nums[i]]++;
            if(store[nums[i]] > floor(nums.size()/2))return nums[i];
        }
        return 0;
    }
};