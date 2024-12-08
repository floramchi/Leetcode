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
   bool isValid(TreeNode* root, long long minVal, long long maxVal) {
        if (!root) return true; // An empty tree is valid.

        // Check if the current node's value violates the BST property.
        if (root->val <= minVal || root->val >= maxVal) return false;

        // Recursively check left and right subtrees with updated ranges.
        return isValid(root->left, minVal, root->val) && 
               isValid(root->right, root->val, maxVal);
    }

    
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};