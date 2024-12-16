class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int index = 0;
        for(int it: spaces) {
            res += s.substr(index,  it-index);
            res += ' ';
            index = it;
        }
        res += s.substr(index);
        return res;
    }
};