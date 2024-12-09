class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
     int n = nums.size();
    vector<int> special(n - 1, 0);  // Store whether adjacent pairs are special

    // Precompute the special array
    for (int i = 0; i < n - 1; ++i) {
        // Check if nums[i] and nums[i + 1] have different parity
        special[i] = ((nums[i] % 2) != (nums[i + 1] % 2)) ? 0 : 1;
    }

    // Build prefix sum array for special
    vector<int> prefix(n, 0);
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + (i - 1 < special.size() ? special[i - 1] : 0);
    }

    // Answer queries using the prefix sum array
    vector<bool> result;
    for (auto& query : queries) {
        int from = query[0], to = query[1];
        // Check if there are any "non-special" pairs in the range [from, to - 1]
        int nonSpecialCount = prefix[to] - prefix[from];
        result.push_back(nonSpecialCount == 0);
    }

    return result;
    }
};