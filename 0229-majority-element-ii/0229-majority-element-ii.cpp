class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) //Boyer Moore method O(n)TC O(1)SC
    {

        //Moore's voting Algorithm
        int winner1=INT_MIN , winner2=INT_MIN; //to avoid any faulty testcases
     int count1=0; //we will keep in account 2 counts as we have to find 2 majority elements
     int count2=0;
     int n = nums.size();

      for(int i=0 ; i<n;i++) //traverse the vector
     {
         if(winner1==nums[i]) //increment the count if winner1 is found
         count1++;
         else if(winner2==nums[i]) //increment the count if winner2 is found
         count2++;

      else if(count1==0) //this condition would be triggered first
         {
             winner1 = nums[i]; //we will assign winner1 to this element
             count1=1;  //make the count 1;
         }

         else if(count2==0)//if a new element is found this condition would be triggered
        {
             winner2 = nums[i]; //we will assign winner2 to this element
             count2=1;  //make the count 1;
        }  
        
         else 
         {
             count1--; //in any other cases decrement the count
             count2--; 
         }

 }

 //Finally checking the winner 1 and winner 2 have count more than floor(n/3)

     
         vector<int> v; //vector ini
         count1=count2=0; //new count 
         for(int i=0;i<n;i++)
         {
//if winner1&winner2 found increment the count
             if(nums[i]==winner1)
             count1++;

             if(nums[i]==winner2)
             count2++;
         }
//push back the winners which satisfy the condition    
         if(count1>n/3) v.push_back(winner1);
         if(count2>n/3) v.push_back(winner2); 

         return v;
        
    }
};
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) // using Unordered map O(n) TC O(n) SC
//     {

//         unordered_map<int,int> m; //unordered map 
//         for(int i=0;i<nums.size();i++) //traverse the vector
//         m[nums[i]]++; //mapping the key value pair

//         vector<int> v; //vector to store majority elements
//         for(auto x:m) // traverse the map
//         {
//             if(x.second>nums.size()/3) //checking freq>ceil(n/3)
//             v.push_back(x.first);
//         }

//         return v;

//        }
// };