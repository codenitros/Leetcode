/*

You are given coins of different denominations and a total amount of money. 
Write a function to compute the number of combinations that make up that amount. 
You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

*/

//solution

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // similar to 0/1 knapsack problem using DP
        int n = coins.size();
        
        //create a table with a 0 case
        int dpTable[n+1][amount+1];
        
        //fill it with zeroes
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                dpTable[i][j] = 0;
            }
        }
        
        //base case it is always possible to make up amount 0 from 0 coins
        dpTable[0][0] = 1;
        
        //for  rest of the cases
        for(int i=1;i<=n;i++)
        {
            // it is always possible to get amount 0 from any number of coins 
            dpTable[i][0] = 1;
            
            for(int j=1;j<=amount;j++)
            {
                //dpTable[i-1][j] isnot using the current coin
                // j >= coin[i-1] checks whether current amount >= current coin value only then it is possible
                dpTable[i][j] = dpTable[i-1][j] + (j >= coins[i-1] ? dpTable[i][j-coins[i-1]] : 0);
            }
        }
        // return the last element which has the answer
        return dpTable[coins.size()][amount];
        
    }
};