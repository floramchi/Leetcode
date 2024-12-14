class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
         int n = nums.size();
    long long result = 0;
    int left = 0; // Left pointer for the sliding window
    
    deque<int> maxDeque; // Monotonic deque to track maximum values
    deque<int> minDeque; // Monotonic deque to track minimum values
    
    for (int right = 0; right < n; ++right) {
        // Maintain the decreasing maxDeque
        while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(right);
        
        // Maintain the increasing minDeque
        while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
            minDeque.pop_back();
        }
        minDeque.push_back(right);
        
        // Shrink the window if the condition is violated
        while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
            ++left; // Move the left pointer forward
            // Remove out-of-bound indices from deques
            if (maxDeque.front() < left) maxDeque.pop_front();
            if (minDeque.front() < left) minDeque.pop_front();
        }
        
        // Count the valid subarrays ending at 'right'
        result += (right - left + 1);
    }
    
    return result;
    }
};