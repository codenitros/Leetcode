/*

There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

 

Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
 

Note:

1 <= costs.length <= 100
It is guaranteed that costs.length is even.
1 <= costs[i][0], costs[i][1] <= 1000

*/

//solution

class Solution {
public:
    int min(int a,int b)
    {
        if(a<=b){
            return a;
        }
        return b;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int num = costs.size();
        int minCost=0;
        int cityA=0,cityB=0;
        vector<int> returns;
        int N = num/2;
        
        //get total cost for city A for 2N people
        for(int i=0;i<num;i++)
        {
            minCost+=costs[i][0];
            //also get a discount for sending to city B instead of A
            returns.push_back(costs[i][1] - costs[i][0]);
        }
        //sort refunds 
        sort(returns.begin(),returns.end());
        
        // subtract the refunds for N people
        for(int i=0;i<N;i++)
        {
            minCost+=returns[i];
        }
        
        return minCost;
    }
};