class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
       // Step 1: Count the frequency of each character
    unordered_map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }

    // Step 2: Create a max-heap (priority queue) based on characters
    // The priority queue stores pairs of <character, frequency>, sorted by character
    priority_queue<pair<char, int>> pq;
    for (auto& [ch, freq] : mp) {
        pq.push({ch, freq});
    }

    string result = ""; // To store the resulting string

    while (!pq.empty()) {
        // Get the lexicographically largest character
        auto [ch, freq] = pq.top();
        pq.pop();

        // Calculate how many times this character can be used in a row
        int useCount = min(freq, repeatLimit);
        result.append(useCount, ch); // Append the character `useCount` times
        freq -= useCount; // Reduce the frequency of the character

        // If the current character cannot be used fully, we need a spacer
        if (freq > 0) {
            if (pq.empty()) {
                // No more characters left to use as a spacer
                break;
            }

            // Get the next largest character as a spacer
            auto [nextCh, nextFreq] = pq.top();
            pq.pop();

            // Add the spacer character once
            result += nextCh;
            nextFreq--;

            // Push the spacer character back into the queue if it still has a frequency left
            if (nextFreq > 0) {
                pq.push({nextCh, nextFreq});
            }

            // Push the original character back into the queue for future use
            pq.push({ch, freq});
        }
    }

    return result;
    }
};