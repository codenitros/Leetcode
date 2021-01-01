/*

Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1

*/

//solution

class Solution {
public:
    /*
    4 - 0100
    3 - 0011
    
    16 - 10000
    15 - 01111
    
    64 - 1000000
    63 - 0111111
    */
    //common pattern so do n & n-1 and compare the result
    bool isPowerOfTwo(int n) {
        if(n==0 || n < 0)return 0;
        return ((n & (n-1)) == 0);
    }
};