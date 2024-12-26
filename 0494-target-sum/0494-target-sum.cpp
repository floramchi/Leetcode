class Solution {
    private:
    int countSubsets(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1; // There's one way to make a sum of 0 (empty subset)
        
        for (int num : nums) {
            for (int j = target; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[target];
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // Check if (totalSum + target) is even and target is achievable
        if ((totalSum + target) % 2 != 0 || totalSum < abs(target)) {
            return 0;
        }
        
        int subsetSum = (totalSum + target) / 2;
        return countSubsets(nums, subsetSum);
    }
};