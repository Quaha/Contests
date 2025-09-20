#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvii = vector<vector<pair<int, int>>>;

const int INF = 2e9;

void detectNegativeCycle(vi& cycle, const vvii& g) {
    
    /*
     * Negative cycle detection algorithm (based on Ford-Bellman algorithm)
     *
     * Checks if there is at least one negative cycle in the
	 * graph and returns the sequence of vertices of the cycle,
	 * if there is one (cycle = {u1, u2, ..., un, u1} or empty)
	 * 
     * g - adjacency lists - g[Ui] = {{Vij, Wij}, ...}, 
	 * Wij - any, Ui >= 0
     * 
     * Time Complexity:   O(N*M)
     * Memory Complexity: O(N + M)
    */
 
	cycle.clear();
 
    int N = g.size();
	int M = 0;
 
	for (int u = 0; u < N; u++) {
		M += g[u].size();
	}
 
	vector<tuple<int, int, int>> edges(M);
	for (int u = 0, i = 0; u < N; u++) {
		for (auto [v, w]: g[u]) {
			edges[i] = {u, v, w};
			++i;
		}
	}
 
	vi dists(N, 0);
	vi path(N, -1);
 
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			auto [u, v, w] = edges[j];
 
			if (dists[v] > dists[u] + w) {
				dists[v] = max(dists[u] + w, -INF);
				path[v] = u;
			}
		}
	}
 
	int cycle_start = -1;
 
	for (int j = 0; j < M; j++) {
		auto [u, v, w] = edges[j];
 
		if (dists[v] > dists[u] + w) {
			cycle_start = u;
			break;
		}
	}
 
	if (cycle_start == -1) {
		return;
	}
 
	for (int i = 0; i < N; i++) {
		cycle_start = path[cycle_start];
	}
 
	cycle.push_back(cycle_start);
	int curr_V = path[cycle_start];
	
	while (curr_V != cycle_start) {
		cycle.push_back(curr_V);
		curr_V = path[curr_V];
	}
 
	cycle.push_back(cycle_start);
 
	reverse(cycle.begin(), cycle.end());
}
