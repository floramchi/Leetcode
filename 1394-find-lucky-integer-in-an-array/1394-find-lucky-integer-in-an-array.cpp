class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++) {
            mp[arr[i]]++;
        }
        
        int max_length = -1;
        for(auto it: mp){
            if(it.second == it.first){
                max_length = max(max_length, it.first);
            }
        }
        return max_length;
    }
};