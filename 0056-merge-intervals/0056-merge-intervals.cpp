//In this approach we first sort the intervals vector (2D vector). We introduce a temporary vector for updating the values and pushing back in our returning vector.We first pushback first pair of elements of intervals (2D vector) in temporary vector. Then we traverse through the intervals vector and compare 1st element of pairs with the 2nd element of temporary pair formed.Then we have two cases 1) if 2nd element of temporary vector is greater than or equal to the 1st element of the iterator pointing pair then we update the 2nd element of the temp vector as max of (2nd element of it,2nd element of temp) 2) else 2nd element of temporary vector is less than the 1st element of the iterator pointing pair then we push back the temporary pair in the 2D vector v formed and we update the value of temp equal to it. then it is incremented 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v; 

        if(intervals.size()==0)
        {
            return v;
        }
        sort(intervals.begin(),intervals.end()); //sort
    
       vector<int> temp = intervals[0]; //we store only two elements in temp
       
  

       for(auto it : intervals)
       {
           if(it[0]<=temp[1])
           {
               temp[1]=max(it[1],temp[1]);
           }
           else 
           {
               v.push_back(temp);
               temp=it;
           }
       }
       v.push_back(temp);
       return v;

        
    }
};