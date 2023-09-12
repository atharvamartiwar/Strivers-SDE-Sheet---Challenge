class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = (int)triangle.size();
        int n = (int)triangle[m-1].size();
       vector<vector<int>> dp(m,vector<int>(n,1e9));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(i==0 && j==0) dp[i][j] = triangle[0][0];
                else
                {
                    int up = 1e9 , upleft=1e9;
                    if(i>0 && j<triangle[i-1].size()) up=triangle[i][j]+dp[i-1][j];
                    
                    if(i>0 && j>0) upleft=triangle[i][j]+dp[i-1][j-1];
                    
                    dp[i][j] = min(up,upleft);
                }
            }
        }
     int min_path = INT_MAX;
           for(int i=0;i<dp[m-1].size();i++)
           {
               min_path = min(min_path,dp[m-1][i]);
           }
        return min_path;
    }
};
