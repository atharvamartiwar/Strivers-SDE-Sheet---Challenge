class Solution {
public:
 bool ispalindrome(string str, int i, int j)
 {
     while(i<j)
     {
         if(str[i++]!=str[j--]) return false;
     }

     return true;
 }

void rec(int index, vector<string>&split, string&s, vector<vector<string>>& res)
 {
     int n = (int)s.size();
     if(index>=n) 
     {
         res.push_back(split);
         return ;
     }

     for(int i=index;i<n;i++)
     {
        if(ispalindrome(s,index,i))
        {
            split.push_back(s.substr(index,i-index+1));
            rec(i+1,split,s,res);
            split.pop_back();
        }
     }

 }
    vector<vector<string>> partition(string s) {
        vector<string>split;
        vector<vector<string>> res;
        rec(0,split,s,res);
        return res;
    }
};