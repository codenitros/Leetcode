/*

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point.
Check if these points make a straight line in the XY plane.

Example 1:

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true 

Constraints:
-->  2 <= coordinates.length <= 1000
-->  coordinates[i].length == 2
-->  -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
-->  coordinates contains no duplicate point.

*/

//solution

class Solution {
public:
    
    float slope(vector<int> a, vector<int> b)
    {
        if(b[0] - a[0] == 0)return 0;
        return (float(b[1] - a[1]) / (b[0] -a[0]));
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(coordinates.size()<=2)
            return true;
        
        float s = slope(coordinates[0],coordinates[1]);
        for(int i=2;i<coordinates.size();i++)
        {
            if(slope(coordinates[i],coordinates[0]) != s)return false;
        }
        return true;
    }
};