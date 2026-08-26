class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // max-heap of {distance, index}, largest distance on top
    priority_queue<pair<int,int>> maxHeap;
    
    for (int i = 0; i < points.size(); i++) {
        int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
        maxHeap.push({dist, i});
        if (maxHeap.size() > k) {
            maxHeap.pop();   // remove the farthest
        }
    }
    
    vector<vector<int>> result;
    while (!maxHeap.empty()) {
        int idx = maxHeap.top().second;
        result.push_back(points[idx]);
        maxHeap.pop();
    }
    return result;
}
};
