class Solution {
public:
   vector<vector<int>>mat;
   vector<vector<int>>dp;
int rec(int i,int j)
    {
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i>=0 && j>=0 && mat[i][j]==1 ) return dp[i][j]=0;
        if(i==0 && j==0) return 1;
         int up = rec(i-1,j);
         int left = rec(i,j-1);
        return dp[i][j]= (up+left);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        mat = obstacleGrid;
        int m = (int)obstacleGrid.size();
        int n = (int)obstacleGrid[0].size();
        dp.resize(m,vector<int>(n,-1));
        return rec(m-1,n-1);

    }
};