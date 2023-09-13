// bottomup approach from bottomright to topleft direction
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m = (int)triangle.size();
//         int n = (int)triangle[m-1].size();
//        vector<vector<int>> dp(m,vector<int>(n,1e9));
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<triangle[i].size();j++)
//             {
//                 if(i==0 && j==0) dp[i][j] = triangle[0][0];
//                 else
//                 {
//                     int up = 1e9 , upleft=1e9;
//                     if(i>0 && j<triangle[i-1].size()) up=triangle[i][j]+dp[i-1][j];
                    
//                     if(i>0 && j>0) upleft=triangle[i][j]+dp[i-1][j-1];
                    
//                     dp[i][j] = min(up,upleft);
//                 }
//             }
//         }
//      int min_path = INT_MAX;
//            for(auto it:dp[m-1])
//            {
//                min_path = min(min_path,it);
//            }
//         return min_path;
//     }
// };
class Solution {
public:
   vector<vector<int>> dp;
   vector<vector<int>> triangle1;
    int rec(int i,int j){
         if(i==0 && j==0) return dp[i][j]=triangle1[0][0];
         if(dp[i][j]!=1e9) return dp[i][j];
         int up = 1e9 , upleft = 1e9;
         if(i>0 && j<triangle1[i-1].size()) up = triangle1[i][j]+rec(i-1,j);
         if(i>0 && j>0) upleft = triangle1[i][j] + rec(i-1,j-1);
         return dp[i][j] = min(up,upleft);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        triangle1 = triangle;
        int m = (int)triangle.size();
        int n = (int)triangle[m-1].size();
        
        dp.resize(m,vector<int>(n,1e9));
        for(int i=0;i<m;i++)
        rec(m-1,i);
        int min_path = INT_MAX;

           for(auto it:dp[m-1])
           {
               min_path = min(min_path,it);
               cout<<it<<" ";
           }
        return min_path;
      

    }
};
// class Solution {
// public:
//    vector<vector<int>> dp;
//    vector<vector<int>> triangle1;
//     int rec(int i,int j){
//         int m = (int)triangle1.size();
//         int n = (int)triangle1[m-1].size();
//          if(i==m-1) return dp[i][j]=triangle1[n-1][j];
//          if(dp[i][j]!=1e9) return dp[i][j];
//          int d = 1e9 , rd = 1e9;
//          if(i<m)  d = triangle1[i][j]+rec(i+1,j);
//          if(i<m && j<n)  rd = triangle1[i][j] + rec(i+1,j+1);
//          return dp[i][j]=min(d,rd);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         triangle1 = triangle;
//         int m = (int)triangle.size();
//         int n = (int)triangle[m-1].size();
        
//         dp.resize(m,vector<int>(n,1e9));
//         rec(0,0);
//         return dp[0][0];      

//     }
// };

