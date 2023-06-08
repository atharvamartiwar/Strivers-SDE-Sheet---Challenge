// //Problem link:https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// class Solution 
// {
// public:
//     int maxProfit(vector<int>& prices) //naive solution
//     {

//         int diff;
//         int profit=0;
//         for(int i=0;i<prices.size();i++)
//         {
//             for(int j=i+1;j<prices.size();j++)
//             {
//                 diff = prices[j]-prices[i];
//                 profit=max(profit,diff);
//             }
//         }
//         return profit;
        
//     }
// };
//In this the intuition is that for a particular price in array the maximum profit will be that (element - min element at its left). so while traversing we will maintain the minimum element at the left.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int res = 0;
    int minleft=INT_MAX;
    for(int i=0;i<prices.size();i++)
    {
        minleft=min(minleft,prices[i]);
        res=max(res,prices[i]-minleft);
    }
    return res;


        
    }
};