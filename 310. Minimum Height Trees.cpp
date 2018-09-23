class Solution
{
  public:
    bool found = false;
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges)
    {
        vector<int> ret;
        if (n == 1)
        {
            ret.push_back(0);
            return ret;
        }
        std::vector<std::vector<int>> graph(n);
        for (const auto &p : edges)
        {
            graph[p.first].emplace_back(p.second);
            graph[p.second].emplace_back(p.first);
        }
        int v = bfs(n, 0, graph);
        int w = bfs(n, v, graph);
        //找到从v到w的路径
        vector<bool> visited(n, false);
        vector<int> path;
        dfs(v, w, graph, visited, path);

        int x = path.size();
        if (x % 2 == 1)
            ret.push_back(path[x / 2]);
        else
        {
            ret.push_back(path[x / 2]);
            ret.push_back(path[x / 2 - 1]);
        }
        return ret;
    }
    void dfs(int v, int w, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &path)
    {
        if (found)
            return;
        visited[v] = true;
        path.push_back(v);
        int size = graph[v].size();
        for (int i = 0; i < size; i++)
        {
            if (graph[v][i] == w)
            {
                found = true;
                path.push_back(w);
                return;
            }
            else if (!visited[graph[v][i]])
                dfs(graph[v][i], w, graph, visited, path);
        }
        if (!found)
            path.pop_back();
    }
    int bfs(int n, int root, vector<vector<int>> &graph)
    {
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(root);
        int last = root;

        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            last = f;
            visited[f] = true;
            int size = graph[f].size();
            for (int i = 0; i < size; i++)
            {
                if (!visited[graph[f][i]])
                {
                    q.push(graph[f][i]);
                }
            }
        }
        return last;
    }
};