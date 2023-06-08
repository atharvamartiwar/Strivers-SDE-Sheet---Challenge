class Solution {
public:
    set<vector<int>> s;
    vector<int> temp;
    
    void subsequences(vector<int>& v, int index) {
        int n = v.size();
        if (index >= n) {
            s.insert(temp);
            return;
        }

        temp.push_back(v[index]);
        subsequences(v, index + 1);
        temp.pop_back();
        subsequences(v, index + 1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the input array
        subsequences(nums, 0);
        
        vector<vector<int>> result(s.begin(), s.end());
        return result;
    }
};