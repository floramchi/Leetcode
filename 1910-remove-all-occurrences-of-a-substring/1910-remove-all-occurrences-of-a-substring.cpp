class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res = "";
        int p2 = part.size();
        
        for(char c: s) {
            res.push_back(c);
            if(res.size() >= p2 && res.substr(res.size() - p2) == part) {
                res.erase(res.size() - p2);
            }
        }
        return res;
    }
};