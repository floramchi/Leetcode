class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--) {
        int mini = INT_MAX; // Track the minimum value
        int minIndex = -1;  // Track the index of the first minimum value

        // Find the minimum value and its first occurrence
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < mini) {
                mini = nums[i];
                minIndex = i;
            }
        }

        // Replace the minimum value with (minimum value * multiplier)
        nums[minIndex] = nums[minIndex] * multiplier;
    }

    return nums; // Return the final state of the array
    }
};