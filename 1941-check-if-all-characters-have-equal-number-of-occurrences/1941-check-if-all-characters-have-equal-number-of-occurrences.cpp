class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mp;
        for(char c: s) {
            mp[c]++;
        }
        
        int temp = mp.begin()->second;
        for(auto it: mp){
            if(it.second != temp){
                return 0;
            }
        }
        return 1;
    }
};