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
class Solution {
public:
pair<bool, int> isheightBalanced(TreeNode *root)
{
    if (root == NULL)
        return {true, 0};
    auto h1 = isheightBalanced(root->left);
    auto h2 = isheightBalanced(root->right);

    return make_pair((h1.first && h2.first && (abs(h1.second - h2.second) <= 1)), 1 + max(h1.second, h2.second));
}
    bool isBalanced(TreeNode* root) {
        return isheightBalanced(root).first;
    }
};