class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Custom comparator for max-heap based on gain in pass ratio
    auto gain = [](const pair<int, int>& a) {
        return (double)(a.first + 1) / (a.second + 1) - (double)a.first / a.second;
    };
    
    auto comp = [&](const pair<int, int>& a, const pair<int, int>& b) {
        return gain(a) < gain(b);
    };

    // Max heap to store classes based on gain
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> maxHeap(comp);

    // Push all classes into the heap
    for (auto& cls : classes) {
        maxHeap.push({cls[0], cls[1]});
    }

    // Add extra students
    while (extraStudents--) {
        auto [pass, total] = maxHeap.top();
        maxHeap.pop();
        maxHeap.push({pass + 1, total + 1});
    }

    // Calculate the average pass ratio
    double result = 0.0;
    while (!maxHeap.empty()) {
        auto [pass, total] = maxHeap.top();
        maxHeap.pop();
        result += (double)pass / total;
    }

    return result / classes.size();
    }
};