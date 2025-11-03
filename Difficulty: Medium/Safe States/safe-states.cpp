class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        if (state[node] != 0) return state[node] == 2;

        state[node] = 1; // mark as visiting

        for (int nei : graph[node]) {
            if (state[nei] == 1) return false;        // cycle detected
            if (!dfs(nei, graph, state)) return false; // if any path unsafe
        }

        state[node] = 2; // mark as safe
        return true;
    }

    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        for (auto& e : edges)
            graph[e[0]].push_back(e[1]);

        vector<int> state(V, 0); // 0=unvisited, 1=visiting, 2=safe
        vector<int> safe;

        for (int i = 0; i < V; i++)
            if (dfs(i, graph, state))
                safe.push_back(i);

        return safe;
    }
};
