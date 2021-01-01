/*

Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.

 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.


Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
*/

//solution


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;
        for(int i:nums){
            hashmap[i]++;
        }
        
        int res=0;
        for(auto p:hashmap){
            int x = p.first;
            
            if(hashmap.find(x+k)==hashmap.end()){
                continue;
            }
            //man this is some crazy code
            // if k=0 then we need to consider only those nums that have repeated more than once
            // if k!=0 then for every x we need to check if x+k is in map 
            res+=(k==0)? (hashmap[x+k]>=2) : hashmap[x+k]>=1;
        }
        
        
        return res;
        
    }
};