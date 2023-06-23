class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
           v[i]=i+1;
        }

         for(int i=0;i<k-1;i++)
        {
           next_permutation(v.begin(),v.end());
        }

        string str="";

        for(int i=0;i<n;i++)
        {
            str+=to_string(v[i]);
        }

        return str;
 }
};