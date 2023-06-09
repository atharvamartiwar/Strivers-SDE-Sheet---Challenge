class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    
    void subsequences(vector<int>& v, int index) {
       int n = v.size();
       res.push_back(temp);
       for(int i=index ; i<n;i++)
       {
           if(i>index && v[i]==v[i-1])
           continue;

           temp.push_back(v[i]);
           subsequences(v,i+1);
           temp.pop_back();
       }
}
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the input array
        subsequences(nums, 0);
        return res;
     }
};