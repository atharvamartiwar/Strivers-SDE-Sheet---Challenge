class Solution {
public:
    bool isSafe(int x,int y, vector<string> &grid)
    {
        int  n = (int)grid.size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][y]=='Q') return false;  //check for same columns
         
         for(int j=0;j<n;j++)
        {
            if(i-j == x-y && grid[i][j]=='Q') return false;
            if(i+j==x+y && grid[i][j]=='Q')  return false;
        }
        }
     return true;

    }


    bool Nqueen(int row, vector<string>&grid,vector<vector<string>>&res)
    {
        int n = (int)grid.size();
       
        if(row>=n)
        {
            res.push_back(grid);
            return true;
        }

        for(int col=0;col<n;col++)
        {
            if(isSafe(row,col,grid))
            {
                grid[row][col]='Q'; //place the Queen 

                Nqueen(row+1,grid,res); //recursion
                grid[row][col]='.'; //backtrack
            }
        }

        return false;
    }


    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> res;
      vector<string> grid(n, string(n, '.'));
      Nqueen(0,grid,res);
      return res;
 }
};