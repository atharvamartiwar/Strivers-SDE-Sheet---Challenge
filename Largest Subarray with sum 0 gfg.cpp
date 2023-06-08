/*You are required to complete this function*/

// class Solution{
//     public:
//     int maxLen(vector<int>&A, int n)
//     {   
//         // Your code here
//         int res=-1;
//         vector<int> v(n,0);
//         v[0]=A[0];
//         for(int i=0;i<n-1;i++)
//         {
//             v[i+1]=v[i]+A[i+1];
//         }
        
//         int sum = accumulate(A.begin(),A.end(),0);
//         if(sum==0) res = n;
        
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i;j<n-1;j++)
//             {
//                 if(v[i]==v[j])
//                 res = max(res,j-i);
//             }
//         }
        
//         return res;
//     }
// };
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
       unordered_map<int,int>m;
       int sum = 0 , res = 0;
       
       for(int i=0;i<n;i++)
       {
           sum+=A[i];
           if (sum ==0) res=i+1;
           
           else if (m.count(sum)) res = max(res,i-m[sum]);
           
           else m[sum]=i;
           
       }
       return res;
       
    }
};
