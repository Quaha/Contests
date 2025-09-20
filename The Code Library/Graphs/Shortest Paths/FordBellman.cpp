#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

using vvii = vector<vector<pair<int, int>>>;

const int INF = 2e9;

void FordBellman(int start_V, vi& dists, vi& path, const vvii& g) {
    
    /*
     * Ford-Bellman algorithm
     *
     * Finds all the shortest distances from the starting
     * vertex to the others (or INF if there is no path, or -INF
	 * if there is no shortest path [negative cycle]) and paths
	 * (previous vertices or -1 if there is no path to)
     * 
     * g - adjacency lists - g[Ui] = {{Vij, Wij}, ...}, 
	 * Wij - any, Ui >= 0
     * 
     * Time Complexity:   O(N*M)
     * Memory Complexity: O(N + M)
    */

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

	dists.assign(N, INF);
	path.assign(N, -1);

	dists[start_V] = 0;

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			auto [u, v, w] = edges[j];

			if (dists[u] != INF && dists[v] > dists[u] + w) {
				dists[v] = max(dists[u] + w, -INF);
				path[v] = u;
			}
		}
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			auto [u, v, w] = edges[j];

			if (dists[u] != INF && dists[v] > dists[u] + w) {
				dists[v] = -INF;
				path[v] = u;
			}
		}
	}	
}