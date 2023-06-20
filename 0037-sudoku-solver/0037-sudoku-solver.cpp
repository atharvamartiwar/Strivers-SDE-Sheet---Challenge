class Solution {
public:

 bool check(int x, int y, int val,vector<vector<char>>&grid)
 {
     int row_subgrid = 3*(x/3);
     int col_subgrid = 3*(y/3);

     for(int i=0;i<9;i++)
     {
         if(grid[x][i]==char('0'+val)) return false; //checking row
         if(grid[i][y]==char('0'+val)) return false; // checking column
         if(grid[row_subgrid + (i/3)][col_subgrid + (i%3)] == char('0'+val)) return false;
     }

     return true;
 }

 bool helper(int row, int col , vector<vector<char>>&grid)
 {
     if(col>=9)
       return helper(row+1,0,grid);
     if(row>=9)
       return true;

    if(grid[row][col]!='.') return helper(row,col+1,grid);

    for(int val=1;val<=9;val++)
    {
        if(check(row,col,val,grid))
        {
            grid[row][col] = char('0'+val);

            if(helper(row,col+1,grid)) return true;

            grid[row][col] = '.';
        }
    }

    return false;
 }
    void solveSudoku(vector<vector<char>>& board) {
      helper(0,0,board);
      
   }
};