/*



Given an array w of positive integers, where w[i] describes the weight of index i, 
write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

    1 <= w.length <= 10000
    1 <= w[i] <= 10^5
    pickIndex will be called at most 10000 times.

Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]

*/



//solution

class Solution {
public:
    vector<int> cummulative; 
    int sum;
    Solution(vector<int>& w) {
        sum=0;
        for(int i=0;i<w.size();i++)
        {
            sum+=w[i];
            cummulative.push_back(sum);
        }
    }
    int binarySearch(int val)
    {
        int low = 0;
        int high = cummulative.size()-1;
        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(cummulative[mid] < val)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
    int pickIndex() {
        int id = rand() % sum;
        return binarySearch(id + 1);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
