/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive).
The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi.
Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex start to vertex end.

Given edges and the integers n, start, and end, return true if there is a valid path from start to end, or false otherwise.

Example 1:
0       1
    2

Input: n = 3, edges = [[0,1],[1,2],[2,0]], start = 0, end = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2

Example 2:
     1            3       
0                      5
     2            4

Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], start = 0, end = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
 

Constraints:

1 <= n <= 2 * 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
1 <= ui, vi <= n - 1
ui != vi
1 <= start, end <= n - 1
There are no duplicate edges.
There are no self edges.
*/

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        if (n == 1) {
            return start == end;
        }
        unordered_map<int, set<int>> g;
        for (auto e : edges) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        set<int> vis;
        return dfs(g, vis, start, end);
    }
    
    bool dfs(unordered_map<int, set<int>> &g, set<int> &vis, int start, int end) {
        if (vis.find(start) != vis.end()) {
            return false;
        }
        vis.insert(start);
        for (auto v : g[start]) {
            if (v == end) {
                return true;
            }
            if (dfs(g, vis, v, end)) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        if (start == end) {
            return true;
        }
        unordered_map<int, set<int>> g;
        for (auto e : edges) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        set<int> vis;
        queue<int> q;
        q.push(start);
        vis.insert(start);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : g[u]) {
                if (v == end) {
                    return true;
                }
                if (vis.find(v) == vis.end()) {
                    vis.insert(v);
                    q.push(v);
                }
            }
        }
        return false;
    }
};
