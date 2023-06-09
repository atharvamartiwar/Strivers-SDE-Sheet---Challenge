class Solution {
public:
   
   void permutations(int id,vector<int> &v ,vector<vector<int>> &s)
   {
       int n = (int)v.size();
       if(id>=n) 
       {
           s.push_back(v);
           return ;
       }

       for(int j = id ; j<=n-1;j++)
       {
           swap(v[j],v[id]);
           permutations(id+1,v,s);
           swap(v[j],v[id]); //backtrack
       }

       return ;
   }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        vector<vector<int>> s;
        permutations(0,nums,s);
        for(auto it:s)
        {
            v.push_back(it);
        } 

        return v;

    }
};
// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> result;
//         result.push_back(nums); // Initial permutation
        
//         int n = nums.size();
        
//         // Iterate through all possible positions to split the vector
//         for (int i = 0; i < n - 1; i++) {
//             int size = result.size();
            
//             // Generate new permutations by inserting the next number at different positions
//             for (int j = 0; j < size; j++) {
//                 for (int k = i + 1; k < n; k++) {
//                     vector<int> perm = result[j];
//                     swap(perm[i], perm[k]);
//                     result.push_back(perm);
//                 }
//             }
//         }
        
//         return result;
//     }
// };