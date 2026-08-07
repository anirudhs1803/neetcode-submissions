class Solution {
public:
    bool runbfs(int node,int parent,unordered_map<int, vector<int>> &adj, vector<bool> &visited){
        queue<pair<int, int>> q;
        q.push({node, parent});
        visited[node]= true;

        while(!q.empty()){
            int element = q.front().first;
            int par = q.front().second;
            q.pop();

            for(auto it: adj[element]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push({it, element});
                }
                else{
                    if(it != par){
                        return true;
                    }
                }
            }

            
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        

        vector<bool> visited(n, false);

        

        unordered_map<int, vector<int>> adj;

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        if(runbfs(0, -1,adj, visited)){
            return false;
        }
        

        for(auto it: visited){
            if(it == false){
                return false;
            }
        }
        return true;
    }
};
