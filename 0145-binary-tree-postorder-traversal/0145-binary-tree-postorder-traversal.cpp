/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     vector<int> ans;
//     void postorder(TreeNode* root)
//     {
//         if(root==NULL) return;
//         postorder(root->left);
//         postorder(root->right);
//         ans.push_back(root->val);

//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         postorder(root);
//         return ans;
//     }
// };
class Solution {
public:
 vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*>st1,st2;
        st1.push(root);
        while(!st1.empty())
        {
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left!=NULL) st1.push(root->left);
            if(root->right!=NULL) st1.push(root->right);
            
        }

        while(!st2.empty())
        {
            TreeNode* r = st2.top();
            ans.push_back(r->val);
            st2.pop();
        }

        return ans;
    }
};