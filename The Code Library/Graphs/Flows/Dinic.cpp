#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

using ii = pair<int, int>;
using vii = vector<pair<int, int>>;
using vvii = vector<vector<pair<int, int>>>;

#define all(x) x.begin(), x.end()

const int INF = 2e9;

struct Dinic {
    // Finds max flow in graph. Works with adjacency lists.
    // Set n (number of vertices) via constructor.
    // Set s (start vertex) and t (target) vertex via constructor or struct fields.
    // Add direct or bidirect edges with addDirect/addBidirect.
    // Calculate max flow with getMaxFlow()


    vvii adj;
    vi p, dists, throughputs;
    int n, s, t;


    Dinic(int n_, int s_, int t_) {
        n = n_;
        s = s_;
        t = t_;
        adj.assign(n, vii());
        p.resize(n);
        dists.resize(n);
    }


    void addDirect(int u, int v, int t) {
        int id = throughputs.size();
        throughputs.resize(throughputs.size() + 2);
        throughputs[id] = t;
        throughputs[id + 1] = 0;
        adj[u].push_back({ v, id });
        adj[v].push_back({ u, id ^ (int)1 });
    }


    void addBidirect(int u, int v, int t) {
        int id = throughputs.size();
        throughputs.resize(throughputs.size() + 2);
        throughputs[id] = t;
        throughputs[id + 1] = t;
        adj[u].push_back({ v, id });
        adj[v].push_back({ u, id ^ (int)1 });
    }


    bool calcDists() {
        fill(all(dists), -1);
        dists[s] = 0;
        queue<int> q;
        q.push(s);


        while (q.size()) {
            int cur = q.front(); q.pop();
            for (const auto& [y, id] : adj[cur])
            {
                int t = throughputs[id];
                if (dists[y] == -1 && t > 0)
                {
                    dists[y] = dists[cur] + 1; q.push(y);
                }
            }
        }


        return dists[t] != -1;
    }
    
    int dfs(int v, int flow) {
        if (flow == 0) return 0;
        if (v == t) return flow;


        for (; p[v] < adj[v].size(); p[v]++)
        {
            const auto& [y, id] = adj[v][p[v]];
            if (dists[y] != dists[v] + 1) continue;
            int pushed = dfs(y, min(flow, throughputs[id]));
            if (pushed > 0)
            {
                throughputs[id] -= pushed;
                throughputs[id ^ (int)1] += pushed;
                return pushed;
            }
        }
        return 0;
    }


    int getMaxFlow() {
        int flow = 0;
        while (calcDists())
        {
            fill(all(p), 0);
            int pushed;
            while (pushed = dfs(s, INF))
                flow += pushed;
        }
        return flow;
    }
};
