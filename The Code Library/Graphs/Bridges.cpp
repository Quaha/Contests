#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vii = vector<pair<int, int>>;

void dfs_b(int curr_V, int last_V, int curr_deep, vi& lowest_deep, vii& bridges, const vvi& g) {

    lowest_deep[curr_V] = curr_deep;
    for (int next_V: g[curr_V]) {
        if (lowest_deep[next_V] == -1) {
            dfs_b(next_V, curr_V, curr_deep + 1, lowest_deep, bridges, g);
        }
    }

    for (int next_V: g[curr_V]) {
        if (next_V != last_V) {
            lowest_deep[curr_V] = min(lowest_deep[curr_V], lowest_deep[next_V]);
        }
    }

    if (lowest_deep[curr_V] == curr_deep && curr_V != last_V) {
        bridges.push_back({curr_V, last_V});
    }
}

// g is a connected simple graph

vii getBridges(const vvi &g) {
    vi lowest_deep(g.size(), -1);
    vii bridges;

    dfs_b(0, 0, 0, lowest_deep, bridges, g);

    return bridges;
}