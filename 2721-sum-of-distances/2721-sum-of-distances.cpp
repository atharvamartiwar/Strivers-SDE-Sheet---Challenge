class Solution {
public:
    std::vector<long long> distance(std::vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n);
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            mp[num].push_back(i);
        }
        for ( auto x : mp) {
            int num = x.first;
            vector<int>&indices  = x.second;
            long long sumBefore = 0;
            long long totalSum = 0;
          
             for(auto x:indices)
             {
                 totalSum+=(long long)x;
             }

            int n = (int)indices.size();
            for (int i = 0; i < n; i++) {
                int index = indices[i];
                long long sumAfter = totalSum-sumBefore-index;
                res[index] += (index*(long long)i);
                res[index] -= (index*(long long)(n-i-1)) ;
                res[index] -= sumBefore;
                res[index] += sumAfter;

                sumBefore+=index;
               
            }
        }

        return res;
    }
};