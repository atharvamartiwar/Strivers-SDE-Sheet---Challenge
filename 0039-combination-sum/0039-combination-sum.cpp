class Solution {
public:
    vector<vector<int>> v; 
    void combination(vector<int>&candidates,int index, vector<int>&temp,int target,int sum)
    {
        int n = (int)candidates.size();
          if(sum==target)
            {
                v.push_back(temp);
                return;
                
            }

         if (sum > target || index >= n) {
            return;
        }


        //if item is picked 
        temp.push_back(candidates[index]);
        sum+=candidates[index];
        combination(candidates,index,temp,target,sum); //we are index not index+1 because same element can be taken any number if times
        //if item is not picked
        temp.pop_back();
        sum-=candidates[index];
        combination(candidates,index+1,temp,target,sum);
        return;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<int> temp;
         combination(candidates,0,temp,target,0);
         return v;
    }
};