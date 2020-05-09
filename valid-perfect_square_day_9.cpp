
/*

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true

*/

//solution

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)return true;
        for(long long int i=1;i * i<=num;i++){
            if((num % i==0) && (num / i == i))return true;
        }
        return false;
    }
};