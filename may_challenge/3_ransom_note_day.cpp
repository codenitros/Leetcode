/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, 
write a function that will return true if the ransom note can be constructed from the magazines ; 
otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Input: ransomNote = "a", magazine = "b"
Output: false

*/

//solution

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len1 = ransomNote.length();
        int len2 = magazine.length();
        if(len1 > len2)return false;
        unordered_map<char,int> hash;
        for(int i=0;i<len2;i++)
        {
            hash[magazine[i]]++;
        }
        for(int i=0;i<len1;i++)
        {
            if(--hash[ransomNote[i]] < 0)return false; 
        }
        
        return true;
    }
};