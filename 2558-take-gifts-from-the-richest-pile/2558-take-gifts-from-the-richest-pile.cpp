class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        
        for(int i=0; i<gifts.size(); i++) {
            pq.push(gifts[i]);
        }
        
        for(int i=0; i<k; i++) {
            int maxPile = pq.top();
            pq.pop();
            
            pq.push(floor(sqrt(maxPile)));
        }
        
        long long total = 0;
        while(!pq.empty()) {
            total += pq.top();
            pq.pop();
        }
        return total;
    }
};