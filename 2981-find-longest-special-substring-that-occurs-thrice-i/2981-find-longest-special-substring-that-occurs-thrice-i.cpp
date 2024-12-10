class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        
        for(int k = n; k > 0; --k) {
            unordered_map<string, int> freq;
            
            for(int i = 0; i <= n - k; i++) {
                string substring = s.substr(i, k);
                
                // Check if the substring is "special" (all characters are the same)
                set<char> unique_chars(substring.begin(), substring.end());
                if(unique_chars.size() == 1){
                    freq[substring]++;
                }
            }
            
            // Check if any substring of this length occurs at least 3 times
            for(auto &it: freq) {
                if(it.second >= 3){
                    return k;
                }
            }
        }
        return -1;
    }
};