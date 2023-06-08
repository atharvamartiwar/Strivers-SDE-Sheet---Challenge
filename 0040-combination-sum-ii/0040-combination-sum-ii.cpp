class Solution {
public:
    vector<vector<int>> v;
    void combination(vector<int>& candidates, int index, vector<int>& temp, int target, int sum) {
        int n = candidates.size();
        
        if (sum == target) {
            v.push_back(temp);
            return;
        }

        if (sum > target || index >= n) {
            return;
        }
     for(int i=index ; i<n ;i++)
     {

         if(i>index && candidates[i]==candidates[i-1]) continue; 
        // If item is picked
        temp.push_back(candidates[i]);
        sum += candidates[i];
        combination(candidates, i + 1, temp, target, sum);
        temp.pop_back();
        sum -= candidates[i];
        }

     }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<int> temp;
        combination(candidates, 0, temp, target, 0);

        return v;
    }
};