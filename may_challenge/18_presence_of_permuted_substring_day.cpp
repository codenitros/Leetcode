/*

Given two strings s1 and s2, write a function to return true if s2 contains 
the permutation of s1. In other words, one of the first string's permutations 
is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

*/

//solution

class Solution {
public:
    
    bool compare(char ar1[],char ar2[])
    {
        for(int i=0;i<26;i++)
        {
            if(ar1[i]!=ar2[i])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int s1len = s1.length();
        int s2len = s2.length();
        int flag=0;
        //corners
        if(s1len == 0 || s2len < s1len)return false;
    
        char letters[26]={0};
        char stri[26]={0};
        for(int i=0;i<s1len;i++)
        {
            letters[s1[i]-'a']++;
            stri[s2[i]-'a']++;
        }
        
        for(int j=s1len;j<s2len;j++)
        {
            if(compare(letters,stri))
            {
                return true;
            }
            stri[s2[j]-'a']++;
            stri[s2[j-s1len]-'a']--;
        }
        if(compare(letters,stri))
        {
            return true;
        }
        return false;
        
        
    }
};