// class Solution {
// public:
//     string getPermutation(int n, int k) {
//         vector<int> v(n);
//         for(int i=0;i<n;i++)
//         {
//            v[i]=i+1;
//         }

//          for(int i=0;i<k-1;i++)
//         {
//            next_permutation(v.begin(),v.end());
//         }

//         string str="";

//         for(int i=0;i<n;i++)
//         {
//             str+=to_string(v[i]);
//         }

//         return str;
//  }
// };
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v(n);
        int fact = 1;
        for(int i=1;i<=n;i++)
        {
           v[i-1]=i;
           fact=fact*(i);
        }

        fact/=n;

        string str = "";
        k = k-1;
        while(1)
        {
            str = str + to_string(v[k/fact]);
            auto it = v.begin();
            v.erase(it + k/fact);
            if(v.size()==0)
            {
                break;
            }
            k = k%fact;
            fact/=v.size();
        }

     return str;
        
 }
};