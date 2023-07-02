class Solution {
public:
    int rec(int n, vector<int>&dp)
    {
        if(n==2) return 2;
        if(n==1) return 1;

       
        if(dp[n]!=-1) return dp[n];
       
        int x = rec(n-1,dp);
        int y = rec(n-2,dp);
       
 
        return dp[n]= x+y;
    }
    int climbStairs(int n) {

        vector<int> dp(n+1,-1);
        return rec(n,dp);
       
        
     }
};

