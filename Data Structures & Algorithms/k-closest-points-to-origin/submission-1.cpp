class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> pq;
        for(int i =0;i< points.size(); i++){
            pq.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], {points[i][0], points[i][1]}});
            if(pq.size()> k){
                pq.pop();
            }
        }
        vector<vector<int>> result;
        while(!pq.empty()){
            auto something=pq.top();
            pq.pop();
            result.push_back({something.second.first, something.second.second});
        }

        return result;
        
    }
};
