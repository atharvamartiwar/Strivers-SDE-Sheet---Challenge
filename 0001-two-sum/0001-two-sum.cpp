// //Brute force everyone knows
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) O(n^2)TC O(1)SC
//     {
        
//         vector<int> num;
//         int n=nums.size();
        
      
 
//         for(int i=0;i<n-1;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(nums[i]+nums[j]==target)
//                 {
//                     num.push_back(i);
//                     num.push_back(j);
//                 }
                  
//             }

//           }
//         return num;
//     }
// };

/*with help of unordered_map : In this method we do the mapping of array elements with their indexes . 
using find function we check is there any (target-a element) in hashtable , 
if present we push the index i and index of (target-a) element through map if not present we continue making our index map.*/
class Solution {
public: 

vector<int> twoSum(vector<int>& a, int target) 
{


     int n=a.size();//size of a vector
     unordered_map<int,int>m;
     vector<int>ans;
     m[a[0]]=0; //putting 1st element and its index in the map
     for(int i=1;i<n;i++) //Run the loop from i=1 to i=a.size()
     {
          
         int rest=target-a[i]; //rest i.e target-a
         if(m.find(rest)!=m.end()) //find function used to find the rest in the map created till now
         {
             ans.push_back(m[rest]);
             ans.push_back(i);
             return ans; //as there is only one sum possible we will return the ans from here only
            
         }
         else m[a[i]]=i; //else we will keep mapping element and its indexes
        
     }
     return ans;
    }
   
};

// //In this Approach we will first sort the vector and using two pointer approach we will evaluate the indexes of desired element 
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target)//O(nlogn)TC and O(1)SC
//     {

//         vector<pair<int,int>>v; //pair of vectors as we have to return original vector indexes (after sorting it may update the array)
//         for(int i=0;i<nums.size();i++)
//         {
//             v.push_back({nums[i],i}); //pushing the element and indexes in vector
//         }

//         sort(v.begin(),v.end()); //sort the vector

//         int i=0, j=nums.size()-1; //Two pointer approach 
//         while(i<j)
//         {
//             int sum=(v[i].first+v[j].first);//check the sum of 1st and last element 
//             if(sum==target)
//             return {v[i].second,v[j].second};
            
//             else if(sum>target) j--; //decrement j ass. pointer 

//             else i++;// increment i ass. pointer
//          }
        

//         return{-1,-1};


//     }
// };