class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
       int n = edges1.size() + 1;
    int m = edges2.size() + 1;
    vector<vector<int>> g1(n), g2(m);

    // Build adjacency lists for both trees
    for (const auto& e : edges1) {
        g1[e[0]].push_back(e[1]);
        g1[e[1]].push_back(e[0]);
    }
    for (const auto& e : edges2) {
        g2[e[0]].push_back(e[1]);
        g2[e[1]].push_back(e[0]);
    }

    // Lambda function to calculate the diameter of a tree and return farthest node distance
    auto findDiameter = [](const vector<vector<int>>& graph, int startNode, int& farthestNode) {
        int n = graph.size();
        vector<int> distance(n, -1);

        // Depth-first search to find farthest node
        function<void(int, int)> dfs = [&](int current, int dist) {
            distance[current] = dist;
            if (dist > distance[farthestNode]) farthestNode = current;
            for (int neighbor : graph[current]) {
                if (distance[neighbor] == -1) {
                    dfs(neighbor, dist + 1);
                }
            }
        };

        farthestNode = startNode;
        dfs(startNode, 0);
        return distance[farthestNode];
    };

    int farthestNode1 = 0, farthestNode2 = 0;

    // Find diameters of both trees
    findDiameter(g1, 0, farthestNode1); // First DFS
    int diameter1 = findDiameter(g1, farthestNode1, farthestNode1); // Second DFS for g1

    findDiameter(g2, 0, farthestNode2); // First DFS
    int diameter2 = findDiameter(g2, farthestNode2, farthestNode2); // Second DFS for g2

    // Minimum diameter after merging
    int maxDiameter = max(diameter1, diameter2);
    maxDiameter = max(maxDiameter, (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1);

    return maxDiameter;
    }
};