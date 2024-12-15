class Solution {
public:
    
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_map<int, int> first;
        unordered_map<int, int> last;
        
        int degree = 0;
        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            count[num]++;
            degree = max(degree, count[num]);
            if(first.find(num) == first.end()) {
                first[num] = i;
            }
            last[num] = i;
        }
        
        int mini_length = nums.size();
        for(auto [num, freq]: count){
            if(freq == degree) {
                mini_length = min(mini_length, last[num] - first[num] + 1);
            }
        }
        return mini_length;
    }
};