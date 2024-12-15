class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int evenSum = 0;
        int oddSum = 0;
        for(int i=0; i<s.size(); i++) {
            mp[s[i]]++;
            if(mp[s[i]] % 2 == 0) {
                evenSum += 2;
            }
        }
        
        for(int i=0; i<s.size(); i++) {
            if(mp[s[i]] % 2 == 1) {
                oddSum ++;
                break;
            }
        }
        return evenSum + oddSum;
    }
};