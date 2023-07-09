class Solution {
public:
//rec(index)-> max sum(0 to ind) without taking adjacent elements
    int rec(vector<int>& nums, int index ,vector<int>&dp )
    {
        if(index==0) return nums[index];
        if(index<0) return 0;

        if(dp[index]!=-1) return dp[index];

        int x = nums[index] + rec(nums,index-2,dp); //pick the element 
        int y = rec(nums,index-1,dp); // Not pick the element 

        return dp[index] =  max(x,y);
    }
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> dp(n,-1);
        return rec(nums,n-1,dp);
    }
};