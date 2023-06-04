// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) 
//     {
//         next_permutation(nums.begin(),nums.end());
//     }
// };

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n=nums.size(),k,l;
        for(k=n-1;k>0;k--)
        {
            if(nums[k-1]<nums[k])
            {
                break;
            }
        }

        if(k<1)
        {
            reverse(nums.begin(),nums.end());
        }

        else
        {
            for(l=n-1;l>k-1;l--) 
            {
                if(nums[l]>nums[k-1])
                {
                    break;
                }
            }

            swap(nums[k-1],nums[l]);
            reverse(nums.begin()+k,nums.end());
        }
      
       
        
    }
};