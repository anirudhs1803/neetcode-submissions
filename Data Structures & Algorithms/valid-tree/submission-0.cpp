class Solution {
public:
    void runbfs(int node,unordered_map<int, vector<int>> &adj, vector<bool> &visited){
        queue<int> q;
        q.push(node);
        visited[node]= true;

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
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1){
            return false;
        }

        vector<bool> visited(n, false);

        

        unordered_map<int, vector<int>> adj;

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        runbfs(0, adj, visited);

        for(auto it: visited){
            if(it == false){
                return false;
            }
        }
        return true;
    }
};
