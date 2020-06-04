/*

Write a function that reverses a string. The input string is given as an array 
of characters char[].

Do not allocate extra space for another array, you must do this by modifying 
the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

*/


//solution

//two pointer method

class Solution {
public:
    void reverseString(vector<char>& s) {

        int p1,p2;
        p1 = 0;
        p2 = s.size()-1;
        char temp;
        while(p1<p2)
        {
            temp = s[p1];
            s[p1] = s[p2];
            s[p2] = temp;
            
            p1++;
            p2--;
        }
        
    }
};