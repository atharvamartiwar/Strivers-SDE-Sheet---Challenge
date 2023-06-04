// class Solution {
// public:

//  // In this approach we will traverse every element of thge matrix , for each element we would check if its zero or not , if its non zero we would replace it with INT_MAX (replacing with INT_MAX and not zero because if we replace it with zero our array would traverse for new zeroes as well) . Then finally we will traverse the matrix and replace INT_MAX with 0;
//     void setZeroes(vector<vector<int>>& matrix) //O(N*M)(N+M)TC O(1)SC
//     {
//          int rows = matrix.size(), col = matrix[0].size(); //n*m matrix

//          //traversing every matrix element and checking that its zero 
//   for (int i = 0; i < rows; i++) {
//     for (int j = 0; j < col; j++) {
//       if (matrix[i][j] == 0) 
//       {  int ind = i - 1;
//         while (ind >= 0) {
//           if (matrix[ind][j] != 0) //assigning every non zero element INT_MAX
//           {
//             matrix[ind][j] =  'INT_MAX';//luckily INT_MAX is not present in leetcode testcases
//           }
//           ind--; //going to the top of the 0th element and traversing the jth coloumn
//         }
//         ind = i + 1; //going to the right of the 0 element 
//         while (ind < rows) {
//           if (matrix[ind][j] != 0) {
//             matrix[ind][j] = 'INT_MAX';
//           }
//           ind++; //going to the bottom of 0 element and traversing the jth coloumn
//         }
//         ind = j - 1; //going to the left of the 0 element and traversing the ith row
//         while (ind >= 0) {
//           if (matrix[i][ind] != 0) {
//             matrix[i][ind] = 'INT_MAX';

//           }
//           ind--;
//         }
//         ind = j + 1; //going to the right of the 0 element and traversing the ith row
//         while (ind < col) {
//           if (matrix[i][ind] != 0) {
//             matrix[i][ind] = 'INT_MAX';

//           }
//           ind++;
//         }
//       }
//     }
//   }
//   for (int i = 0; i < rows; i++) { //finally traversing the whole matrix and replacing INT_MAX with 0;
//     for (int j = 0; j < col; j++) {
//       if (matrix[i][j] == 'INT_MAX') {
//         matrix[i][j] = 0;
//       }
//     }
//   }
        
        
//     }
// };

// class Solution { 
// public:

//  //In this approach we will make two extra vectors of size equal to number of rows and coloumn respectively , Now we will traverse the matrix and check for zero . Then for that zero we will make corresponding i and j zero in the extra vectors taken . Then finally we will traverse the matrix and check corresponding (i,j )vector position have 0 or not , if anyone of that is zero we will make that matrix position 0.
//     void setZeroes(vector<vector<int>>& matrix)  //O(n*m)TC O(N+M)SC
//     {
//         int rows = matrix.size() , col = matrix[0].size(); 
//         vector<int>v1(rows,-1) , v2(col,-1); //dummy vectors of size equal to rows and columns
//         for(int i=0;i<rows;i++) /*for every 0 encountered in matrix , 
//         we will make corresponding dummy vector posiion 0*/ 
//         {
//             for(int j=0;j<col;j++)
//             {
//                 if(matrix[i][j]==0)
//                 {
//                     v1[i]=0;
//                     v2[j]=0;
//                 }
//             }
//         }

//         for(int i=0;i<rows;i++) //now we will traverse the matrix and check if corresponding i,j value in dummy vectors are zero or not , if anyone of them is zero we will assign zero to that matrix position
//         {
//             for(int j=0;j<col;j++)
//             {
//                 if(v1[i]==0 || v2[j]==0)
//                 {
//                     matrix[i][j]=0;
//                 }
//             }
//         }
         
        
        
//     }
// };
// class Solution { 
// public:/*optimization of the dummy vector approach , instead of taking 2 dummy vectors we will make 1st row and 1st column the value assigning vectors . while traversing the 2nd time we would traverse from reverse because the value of the dummy vector should not change , traversing from starting would update the dummy vector and update the corresponding values. Since matrix[0][0] are overlapping we will use separate variable col0 to check if the 0th column has 0 or not and use matrix[0][0] to check if the 0th row has 0 or not.*/
// //Finally we will traverse from reverse and check if matrix[i][0]==0 || matrix[0][j]==0 and if true set matrix[i][j]=0 else continue


//     void setZeroes(vector<vector<int>>& matrix) 
//     {
//          int col0=1 , rows=matrix.size() , col=matrix[0].size();
//          for(int i=0;i<rows;i++) // traverse the matrix but we would not disturb the 1st column
//          {
//              if(matrix[i][0]==0) col0=0; //we will check if any element in 1st column is zero or not 
//              for(int j=1;j<col;j++)
//              if(matrix[i][j]==0) // for every 0 found we will assign 0 the corresponding 0th row and 0th column
//              matrix[i][0] = matrix[0][j]=0;
//          }

//          for(int i =rows-1;i>=0;i--) //finally traverse the matrix in reverse
//          {
//              for(int j=col-1;j>=1;j--) //do not disturb the first column
//              {
//                  if(matrix[i][0]==0 || matrix[0][j]==0) 
//                  //for every i,j while traversing the matrix we will check the corresponding dummy vectors value
//                  //if anyone of them is zero , assign zero at that position of matrix
//                  matrix[i][j]=0;
//              }

//              if(col0==0)  matrix[i][0]=0; //At last we update the values because if we disturb the 1st column we end up disturbing the overlapping 1st row.
//          }

         
        
        
//     }
// };
class Solution {
public:

//same solution as the unoptimized dummy vector solution , instead of storing corresponding i,j value in vector we store that value in unordered set 
    void setZeroes(vector<vector<int>>& matrix) //O(m*n)TC O(m+n)SC
    {
       unordered_set<int> x,y;
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++) //traverse the matrix
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0) //store corresponding i,j values in unordered set 
                {
                    y.insert(j);
                    x.insert(i);
                }
            }
        }
        for(auto it: x)
        {
            for(int j=0;j<m;j++) // making the corresponding row 0 for every row stored in the set
            matrix[it][j]=0;
        }
        for(auto it: y)
        {
            for(int i=0;i<n;i++) // making the corresponding column 0 for every column stored in the set
            matrix[i][it]=0;
        }
    }
};