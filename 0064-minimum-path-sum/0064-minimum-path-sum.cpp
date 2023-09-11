// //recusrsion + memoization
// class Solution {
// public:
//     vector<vector<int>>mat;
//     vector<vector<int>>dp;
//     int rec(int i,int j)
//     {
//         if(i<0 || j<0) return INT_MAX;
//         if(i==0 && j==0) return dp[i][j]=mat[i][j];
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int op1 = INT_MAX;
//         int op2 = INT_MAX;
//         if(i>0)  op1 = mat[i][j] + rec(i-1,j);
//         if(j>0)  op2 = mat[i][j] + rec(i,j-1);

//         return dp[i][j]=min(op1,op2);

//     }
//     int minPathSum(vector<vector<int>>& grid){
//         mat = grid;
//         int m = grid.size();
//         int n = grid[0].size();
//         dp.resize(m,vector<int>(n,-1));
//         return rec(m-1,n-1); 
//     }
// };
class Solution {
public:
   int minPathSum(vector<vector<int>>& grid){
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up = grid[i][j], left = grid[i][j];
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else
                {
                    if(i>0) up+=dp[i-1][j];
                    else up+= 1e9;
                    if(j>0) left+=dp[i][j-1];   
                    else left+= 1e9;
                    dp[i][j] = min(up,left);
                }
            }
        }

        return dp[m-1][n-1];


    }
};