class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Step 2: Perform DFS to count valid components
        int components = 0;
        vector<bool> visited(n, false);
        
        // Use long long to handle large sums
        function<long long(int, int)> dfs = [&](int node, int parent) {
            visited[node] = true;
            long long subtreeSum = values[node]; // Use long long
            
            for (int neighbor : adj[node]) {
                if (neighbor != parent && !visited[neighbor]) {
                    subtreeSum += dfs(neighbor, node);
                }
            }
            
            // If the subtree sum is divisible by k, it can form a valid component
            if (subtreeSum % k == 0) {
                components++;
                return 0LL; // Reset this subtree's contribution
            }
            
            // Otherwise, return the remaining sum for the parent to process
            return subtreeSum;
        };
        
        dfs(0, -1);
        return components;
    }
};