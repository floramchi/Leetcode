class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> v;
        //int n = prices.size();
        v = prices;
        for(int i=0; i<prices.size(); i++){
            for(int j=i+1; j<prices.size(); j++) {
                if(prices[j] <= prices[i]) {
                    v[i] = prices[i] - prices[j];
                    break;
                }
            }
           
        }
        
        return v;
    }
};