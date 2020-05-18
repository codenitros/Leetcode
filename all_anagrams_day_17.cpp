/*

Given a string s and a non-empty string p, find all the start indices of p's 
anagrams in s.

Strings consists of lowercase English letters only and the length of both 
strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

*/

//solution

class Solution {
public:
    
    bool compare(char ar1[],char ar2[])
    {
        for(int i=0;i<256;i++)
        {
            if(ar1[i]!=ar2[i])return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> res; 
        int m = p.length();
        int n = s.length();
        
        if(n==0)return res;
        if(m > n)return res;
        
        
        //frequency of letters in pattern & s
        char countp[256] = {0};
        char counts[256] = {0};
        for(int i=0;i<m;i++)
        {
            countp[p[i]]++;
            counts[s[i]]++;
        }
        
        // remaining characters of s
        //using sliding window
        for(int j=m;j<n;j++)
        {
            if(compare(countp,counts))
            {
                res.push_back(j-m);
            }
            counts[s[j]]++;    
            counts[s[j-m]]--;  // remove the first letter from the current window
        }
        
        
        // same thing for last window manually
        if(compare(countp,counts))
        {
            res.push_back(n-m);
        }
        
        return res;
        
    }
};

       