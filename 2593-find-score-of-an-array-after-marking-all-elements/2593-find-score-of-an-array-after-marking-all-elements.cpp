class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
    vector<bool> marked(n, false); // To track which elements are marked
    long long score = 0;

    // Create a vector of pairs to store the value and index of each element
    vector<pair<int, int>> elements;
    for (int i = 0; i < n; i++) {
        elements.push_back({nums[i], i});
    }

    // Sort elements by value, and by index in case of ties
    sort(elements.begin(), elements.end());

    // Process elements in sorted order
    for (auto& [value, index] : elements) {
        // If the current element is already marked, skip it
        if (marked[index]) continue;

        // Add its value to the score
        score += value;

        // Mark this element and its adjacent elements
        marked[index] = true;
        if (index > 0) marked[index - 1] = true; // Mark left neighbor
        if (index < n - 1) marked[index + 1] = true; // Mark right neighbor
    }

    return score;
    }
};