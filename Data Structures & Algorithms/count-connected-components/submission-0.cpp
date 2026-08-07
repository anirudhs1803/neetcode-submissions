class Solution {
public:
    int runbfs(int node,unordered_map<int, vector<int>> &adj,vector<bool> &visited){
        queue<int> q;
        visited[node] = true;
        q.push(node);
        int counter = 0;

        while(!q.empty()){
            int element = q.front();
            q.pop();

            for(auto it: adj[element]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        
        return 1;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

        }

        vector<bool> visited(n, false);
        int count =0;

        for(int i =0; i< n ; i++){
            if(!visited[i]){
                count+=runbfs(i, adj, visited);
            }
        }
        return count;
    }
};
