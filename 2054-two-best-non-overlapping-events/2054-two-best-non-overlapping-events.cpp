class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int n = events.size();
    vector<int> maxValues(n, 0); // To store maximum values up to index i
    maxValues[0] = events[0][2]; // The value of the first event

    // Step 2: Compute prefix max values
    for (int i = 1; i < n; i++) {
        maxValues[i] = max(maxValues[i - 1], events[i][2]);
    }

    int result = 0;

    // Step 3: Iterate through each event and compute the maximum sum
    for (int i = 0; i < n; i++) {
        // Event[i] = [startTime, endTime, value]
        int currValue = events[i][2];
        int startTime = events[i][0];

        // Binary search to find the latest event that ends before the current event starts
        int low = 0, high = i - 1, bestIndex = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][1] < startTime) {
                bestIndex = mid; // Update bestIndex and search for a later event
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // If we found a valid event, consider the maximum sum
        if (bestIndex != -1) {
            currValue += maxValues[bestIndex];
        }

        // Update the result
        result = max(result, currValue);
    }

    return result;
    }
};