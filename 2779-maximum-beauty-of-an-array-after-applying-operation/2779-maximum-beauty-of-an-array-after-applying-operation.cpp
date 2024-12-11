class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, maxValue = 0;
        
        for(int right = 0; right < n; right++) {
            if(nums[right] - nums[left] > 2 * k){
                left++;
            }
            maxValue = max(maxValue, right - left + 1);
        }
        return maxValue;
    }
};