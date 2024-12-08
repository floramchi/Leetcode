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
    TreeNode* findMin(TreeNode* root) {
        while(root->left) {
            root = root->left;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
       if (!root) return NULL;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);  // Recurse to the left subtree
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);  // Recurse to the right subtree
    } else {
        // Node to be deleted is found
        if (!root->left) {
            // Case 1: Node has only a right child or no children
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            // Case 2: Node has only a left child
            TreeNode* temp = root->left;
            delete root;
            return temp;
        } else {
            // Case 3: Node has two children
            TreeNode* temp = findMin(root->right);  // Find the minimum value in the right subtree
            root->val = temp->val;  // Replace the current node's value with the minimum value
            root->right = deleteNode(root->right, temp->val);  // Delete the duplicate node
        }
    }

    return root;
    }
};