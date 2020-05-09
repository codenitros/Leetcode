/*

Given a string, find the first non-repeating character in it and return it's index. 
If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
*/

//solution

class Solution {
public:
    int firstUniqChar(string s) {
        
        pair<int,int> arr[256];

        for(int i=0;s[i];i++){
            (arr[s[i]].first)++;
            arr[s[i]].second = i;
        }
        int res = INT_MAX,flag=0;;
        for(int i=0;i<256;i++)
        {
            if(arr[i].first==1){
                flag = 1;
                res = min(res,arr[i].second);
            }
        }
        if(flag){return res;}else{
            return -1;
        }
        
    }
};