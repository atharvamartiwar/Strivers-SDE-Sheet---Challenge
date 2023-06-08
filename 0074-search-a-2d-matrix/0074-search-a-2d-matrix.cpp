class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = (int) matrix.size();
        if(n==0) return false;
        int m = (int) matrix[0].size();

        int ans = -1;
        int low =0 , high = n-1;

        while(low<=high)
        {
            int mid = (low+high)/2;
            if(matrix[mid][0]<=target && matrix[mid][m-1]>=target)
            {
                ans = mid;
                break;
            }

            if(matrix[mid][0]>target)
            {
                high = mid-1;
                continue;
            }

            low = mid+1;
        }

        if(ans==-1) return false;
        return binary_search(matrix[ans].begin(),matrix[ans].end(),target);
        
    }
};