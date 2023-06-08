

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) //using map O(n)TC , O(n) SC
//     {
//         int majorityelement; //res

//         unordered_map<int,int> m;//using unordered map 
//        for(int i=0;i<nums.size();i++) //traversing the array
//        {
//            m[nums[i]]++;  //mapping the key value pair
//        }

//        for(auto x:m)  //traversing the created map
//        {
//            if(x.second>nums.size()/2) //for majority, frequency must be greater than length/2
//            majorityelement=x.first;
//        }

//        return majorityelement; //return the element


//         }
// };
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) //using sorting and intuition O(nlogn) TC , O(1)SC
//     {
//        int res; //result
//        int n=nums.size();
//        sort(nums.begin(),nums.end());//sort the vector
//        for(int i=0;i<n;i++)
//        {
//            res = nums[n/2]; //element at the middle is the majority element
//        }

//        return res;  //return the result
       
       
//        }
// };


class Solution {
public:
    int majorityElement(vector<int>& nums) ////Boyer Moore method O(n) TC O(1) SC
    {

      int majorityelement;
      int count =0;
      for(int i=0;i<nums.size();i++) //Traverse the array
      {
          if(count==0)
           majorityelement=nums[i]; 
     //we will assign the value to majority element which will be encountered first

     if(majorityelement==nums[i]) //if same maj.element is encountered increment the count
           count +=1; 
           else
           count -=1;  //if a different element is encountered decrement the count
      }

      return majorityelement;

        
    }
};
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) //naive approach O(n^2)
//     {

//         int i;
//         int count=0;
//         for( i=0;i<nums.size();i++)//traversing the array
//         {
//             for(int j=i+1;j<nums.size();i++) //for each element check the same element
//             {
//                 if(nums[j]==nums[i])
//                 count++; //increment the count
                 
//             }
//             if(count>nums.size()/2) 
//             break;

//            }

//         return nums[i];
//         }
// };