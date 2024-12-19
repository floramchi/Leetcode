class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int st = 0, e = s.size()-1;
        while(st <= e) {
            if(vowels.find(s[st]) == vowels.end()) {
                st++;
            }
            else if(vowels.find(s[e]) == vowels.end()) {
                e--;
            }
            else {
                swap(s[st], s[e]);
                st++;
                e--;
            }
            
        }
        return s;
    }
};