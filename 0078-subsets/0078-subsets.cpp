class Solution {
public:

    set<vector<int>> vx;
    void subsequences(vector<int> &v,int index , vector<int> & temp)
    {
        int n = v.size();
        if(index>=n)  //Base Case 
        {
            vx.insert(temp);
            return;
            
            
        }
        // if item is picked
        temp.push_back(v[index]);
        subsequences(v,index+1,temp);
        //if item is not picked
        temp.pop_back(); 
        subsequences(v,index+1,temp);
        return;
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        subsequences(nums,0,temp);
        vector<vector<int>>b(vx.begin(),vx.end());
       
        return b;

    }
};