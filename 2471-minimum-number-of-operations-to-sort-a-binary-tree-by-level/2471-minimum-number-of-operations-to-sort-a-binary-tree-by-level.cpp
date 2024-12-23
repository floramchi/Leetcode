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
    int minSwapsToSort(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int>> arr_with_indices(n);
    
    // Pair each element with its index
    for (int i = 0; i < n; i++) {
        arr_with_indices[i] = {arr[i], i};
    }
    
    // Sort the array based on values
    sort(arr_with_indices.begin(), arr_with_indices.end());
    
    // To keep track of visited elements
    vector<bool> visited(n, false);
    int swaps = 0;
    
    // Go through all elements to find cycles
    for (int i = 0; i < n; i++) {
        // If already visited or already in the correct place, skip
        if (visited[i] || arr_with_indices[i].second == i) {
            continue;
        }
        
        // Find the cycle
        int cycle_size = 0;
        int j = i;
        
        while (!visited[j]) {
            visited[j] = true;
            j = arr_with_indices[j].second;
            cycle_size++;
        }
        
        // If there is a cycle of size k, we need (k-1) swaps to sort it
        if (cycle_size > 1) {
            swaps += (cycle_size - 1);
        }
    }
    
    return swaps;
}

    
int minimumOperations(TreeNode* root) {
        if (!root) return 0;
    
    vector<vector<int>> levels;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    
    // BFS to collect nodes at each level
    while (!q.empty()) {
        auto node = q.front().first;
        int level = q.front().second;
        q.pop();
        
        if (levels.size() <= level) {
            levels.push_back({});
        }
        
        levels[level].push_back(node->val);
        
        if (node->left) q.push({node->left, level + 1});
        if (node->right) q.push({node->right, level + 1});
    }
    
    int total_swaps = 0;
    
    // For each level, calculate the minimum swaps needed to sort it
    for (auto& level : levels) {
        total_swaps += minSwapsToSort(level);
    }
    
    return total_swaps;
    }
};