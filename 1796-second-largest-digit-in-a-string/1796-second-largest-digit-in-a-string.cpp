class Solution {
public:
    int secondHighest(string s) {
        vector<int> digits;
        int n = s.length();
        for(int i=0; i<n; i++) {
            if(s[i] >= '0' && s[i] <= '9'){
                int temp = s[i] - '0';
                digits.push_back(temp);
            }
        }
        
        if(digits.size() <= 1){
            return -1;
        } 
        
        int largest = -1, second  = -1;
        for(int i=0; i<digits.size(); i++) {
            largest = max(digits[i], largest);
        }
        
        for(int i=0; i<digits.size(); i++) {
            if(digits[i] > second && digits[i] < largest){
                second = digits[i];
            }
        }
        return second;
    }
};