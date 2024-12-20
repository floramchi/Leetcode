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
    void helper(TreeNode* left, TreeNode* right, int level){
        if(!left || !right) return;
        
        if(level % 2 == 1) {
            swap(left->val, right->val);
        }
        helper(left->left, right->right, level+1);
        helper(left->right, right->left, level+1);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return NULL;
        int level = 1;
        helper(root->left, root->right, level);
        return root;
    }
};